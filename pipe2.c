#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exec1();
void exec2();
void exec3();

int pid;
int pipe1[2];
int pipe2[2];

void main() {

  // create pipe1
  if (pipe(pipe1) == -1) {
    perror("bad pipe1");
    exit(1);
  }

  // fork (cat /etc/passwd)
  if ((pid = fork()) == -1) {
    perror("bad fork1");
    exit(1);
  } else if (pid == 0) {
    // stdin --> cat --> pipe1
    exec1();
  }
  // parent

  // create pipe2
  if (pipe(pipe2) == -1) {
    perror("bad pipe2");
    exit(1);
  }

  // fork (grep root)
  if ((pid = fork()) == -1) {
    perror("bad fork2");
    exit(1);
  } else if (pid == 0) {
    // pipe1 --> grep --> pipe2
    exec2();
  }
  // parent

  // close unused fds
  close(pipe1[0]);
  close(pipe1[1]);

  // fork (cut ...)
  if ((pid = fork()) == -1) {
    perror("bad fork3");
    exit(1);
  } else if (pid == 0) {
    // pipe2 --> cut --> stdout
    exec3();
  }
  // parent


}


void exec1() {
  // input from stdin (already done)
  // output to pipe1
  dup2(pipe1[1], 1);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  // exec
  execlp("cat", "cat", "/etc/passwd", NULL);
  // exec didn't work, exit
  perror("bad exec cat /etc/passwd");
  _exit(1);
}

void exec2() {
  // input from pipe1
  dup2(pipe1[0], 0);
  // output to pipe2
  dup2(pipe2[1], 1);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  close(pipe2[0]);
  close(pipe2[1]);
  // exec
  execlp("grep", "grep", "root", NULL);
  // exec didn't work, exit
  perror("bad exec grep 500");
  _exit(1);
}

void exec3() {
  // input from pipe2
  dup2(pipe2[0], 0);
  // output to stdout (already done)
  // close fds
  close(pipe2[0]);
  close(pipe2[1]);
  // exec
  execlp("cut", "cut", "-d:", "-f1,6", NULL);
  // exec didn't work, exit
  perror("bad exec cut -c 1-255");
  _exit(1);
}
