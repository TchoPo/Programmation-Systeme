

#OBJETS = useComplexe.o complexe.o
#CC = gcc
#CFLAGS = -Wall -g
#useComplexe : $(OBJETS)
#	$(CC) $(CFLAGS) $(OBJETS) -o useComplexe
#useComplexe.o : useComplexe.c complexe.h 
#	$(CC) $(CFLAGS) -c useComplexe.c
#complexe.o : complexe.c complexe.h 
#	$(CC) $(CFLAGS) -c complexe.c


#all : $(APPLI) clean
#$(APPLI) : $(APPLI).o complexe.o
#	gcc -Wall $(APPLI).o complexe.o -o $(APPLI) -lm
#$(APPLI).o : $(APPLI).c complexe.h
#	gcc -Wall -c $(APPLI).c
#complexe.o : complexe.c complexe.h 
#	gcc -Wall -c complexe.c

#clean : $(APPLI)
#	rm -f *.o

compile = gcc -Wall -O3
objet = $(compile) -c 
executable = $(compile) -o 
objetsFiles = complexe.o $(APPLI).o 

all:$(APPLI) run

$(APPLI): $(objetsFiles)
	$(compile) $(objetsFiles) -o $(APPLI) -lm 

$(APPLI).o: $(APPLI).c complexe.h
	$(objet) $(APPLI).c

complexe.o: complexe.c complexe.h
	$(objet) complexe.c

clean:run
	rm -f *.o
run: $(APPLI)
	./$(APPLI)
