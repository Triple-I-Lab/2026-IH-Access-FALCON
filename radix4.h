#include <math.h>
#include <stdint.h>
#include <string.h>
#include "fft.h"




void radix4_1024(fpr f[1024]);
void radix4_512(fpr f[512]);
void ir4_1024(fpr f[1024]);
void ir4_512(fpr f[512]);
void print_tf();