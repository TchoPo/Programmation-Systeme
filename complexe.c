#include <stdlib.h>
#include <stdio.h>
#include "complexe.h"
int main () {
Complexe z1, z2, z3;
z1 = nouveauComplexe (1., 5.);
z2 = nouveauComplexe (1., 1.);
z3 = plus (z1, z2 );
printf ("Module de z3 : %f\n ", module (z3));
printf ("Argument de z3 : %f\n ", argument (z3));
return EXIT_SUCCESS;
}
