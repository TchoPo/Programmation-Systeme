#include <math.h>
#include "complexe.h"
Complexe nouveauComplexe (double r, double i ) {
Complexe z;
z.re = r, z.im = i;
return z;
}
Complexe plus ( Complexe z1, Complexe z2) {
return nouveauComplexe (z1.re+z2.re, z1.im+z2.re);
}
Complexe moins ( Complexe z1, Complexe z2) {
return nouveauComplexe (z1.re-z2.re, z1.im-z2.re);
}
double module (Complexe z) {
return sqrt (z.re*z.re + z.im*z.im);
}
double argument (Complexe z) {
return atan (z.im / z.re);
}
