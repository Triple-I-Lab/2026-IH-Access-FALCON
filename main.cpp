#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fft.h"
#include "radix2.h"
#include "radix4.h"
#include "radix8.h"
#include "radix16.h"

int main()
{
	fpr a[1024], c[512], d[512];
	fpr b[1024];
	printf(" input fft 1024 \n ");
	for (int i = 0; i < 512; i++) {
		a[i].v = i; b[i].v =  2;
	}
	for (int i = 512; i < 1024; i++) {
		a[i].v = 0; b[i].v = 2;
	}
	for (int i = 0; i < 512; i++) {
     	c[i].v = i; d[i].v = i + 1;
	}
	//a[0].v = 2; a[256].v = 3; a[512].v = 1; a[768].v = 14;
	//a[1].v = 3; a[257].v = 2; a[513].v = 14; a[769].v = 1;
	//c[0].v = 9; d[0].v = 9;  c[3].v = 5; d[3].v = 5;
	printf("\n radix-2 FFT n =1024 result  \n ");
	radix2_1024(a);
	printf(" \n \n "); printf(" \n \n "); 
	for (int i = 0; i < 24; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}
	ir2_1024(a);


	printf("\n radix-2 IFFT  \n "); printf(" \n \n "); 
	for (int i = 0; i < 48; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}

	radix2_512(c);
	printf(" \n \n "); printf(" radix-2 FFT n = 512 result  \n \n "); 
	for (int i = 0; i < 16; i++) {
		printf("c[%d] = %lf, ", i, c[i].v);
	}
	ir2_512(c);
	printf("\n \n IFFT result "); printf(" \n \n "); 
	for (int i = 0; i < 16; i++) {
		printf("c[%d] = %lf, ", i, c[i].v);
	}
	printf(" \n \n "); printf(" \n radix4_1024 FFT result\n ");
	radix4_1024(b);
	for (int i = 0; i < 24; i++) {
		printf("b[%d] = %lf, ", i, b[i].v);
	}
	printf(" \n \n  IFFT radix-4"); printf(" \n \n ");
	ir4_1024(b);
	for (int i = 0; i < 32; i++) {
		printf("b[%d] = %lf, ", i, b[i].v);
	}

	printf(" \n \n "); printf(" \n radix8_1024 result \n ");
	radix8_1024(a);
	for (int i = 0; i < 16; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}
	printf(" \n \n "); printf(" \n iFFT8_1024 \n ");
	ir8_1024(a);
	for (int i = 0; i < 16; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}

	printf(" \n \n "); printf(" \n  radix16_512 \n ");
	radix16_512(c);
	for (int i = 0; i < 16; i++) {
		printf("c[%d] = %lf, ", i, c[i].v);
	}
	printf(" \n \n "); printf(" \n radix16 IFFT \n ");
	ir16_512(c);
	for (int i = 0; i < 16; i++) {
		printf("c[%d] = %lf, ", i, c[i].v);
	}
	
	radix16_1024(a);
	printf("\n  \n Radix 16/2 for 1024"); printf(" \n \n ");
	for (int i = 0; i < 32; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}
	ir16_1024(a);
	printf(" \n \n  IFFT result"); printf(" \n \n ");
	for (int i = 0; i < 32; i++) {
		printf("a[%d] = %lf, ", i, a[i].v);
	}
	printf(" \n \n "); printf(" \n \n ");
	//print_tf2();
	fpr a8[8],b8[8],c8[8];

	for (int i = 0; i < 8; i++) {
		a8[i].v = i+1;
		c8[i].v = 0;
	}
	b8[0].v = 1; b8[1].v = 2; b8[2].v = 3; b8[3].v = 4; b8[4].v = 1; b8[5].v = 2; b8[6].v = 3; b8[7].v = 4;
	
	
	multconvolution(c8, a8, b8);
	printf(" \n \n "); printf(" \n Test  Multiply by convolution \n ");
	for (int i = 0; i < 8; i++) {
		printf("c8[%d] = %lf, ", i, c8[i].v);
	}
	fft8(a8);
	printf(" \n \n "); printf(" \n  8 FFT \n ");
	for (int i = 0; i < 8; i++) {
		printf("a8[%d] = %lf, ", i, a8[i].v);
	}
	fft8(b8);
	printf(" \n \n "); printf(" \n  8 FFT \n ");
	for (int i = 0; i < 8; i++) {
		printf("b8[%d] = %lf, ", i, b8[i].v);
	}
	for (int i = 0; i < 4; i++) {
		FPC_MUL(c8[i], c8[i + 4], a8[i], a8[i + 4], b8[i], b8[i + 4]);
	}
	ifft8(c8);
	printf(" \n \n "); printf(" \n  8 iFFT \n ");
	for (int i = 0; i < 8; i++) {
		printf("c8[%d] = %lf, ", i, c8[i].v);
	}
	return 0;
}