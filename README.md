# 2026-TCAS-II-FALCON-FFT
The Fast Fourier Transform (FFT) is a fundamental component of the Falcon framework. This project presents the source code for a higher mixed-radix approach to accelerate FFT/IFFT computations in Falcon. The implementation is developed based on the Falcon team’s open-source code, available at: https://falcon-sign.info/

The project includes the following files:

fft.cpp, fft.h: Adapted from the original fft.c provided by the Falcon team and modified to operate as a standalone implementation. These files include two FFT and two IFFT functions corresponding to the two parameter sets of $n$ in Falcon.

radix2.cpp, radix2.h: Our optimized radix-2 FFT/IFFT implementation for Falcon.

radix4.cpp, radix4.h: Implementation of mixed-radix 4/2 FFT/IFFT algorithms.

radix8.cpp, radix8.h: Implementation of mixed-radix 8/4 FFT/IFFT algorithms.

radix16.cpp, radix16.h: Implementation of mixed-radix 16/2 FFT/IFFT algorithms.

main.cpp: The main function used to test all submodules. At the beginning of this file, users can input arbitrary polynomial coefficients $f$ for verification.

The Fast Fourier Transform for a polynomial computes $f$($\zeta$) for all roots of $\phi$ (over C). $\phi$ has distinct roots in C, leading to $n$ values $f(\zeta)$, each being a complex number, with a real and an imaginary part. Storage space requirements are then 2$n$ floating-point numbers. However, if $f$ is real, then, for every root $\zeta$ of $\phi$, $\bar{\zeta}$ is also a root of $\phi$ and $\bar{f(\zeta)}$ = $f(\bar{\zeta})$. Thus, the FFT representation is redundant, and half of the values can be omitted, reducing storage space requirements to $n$/2 complex numbers, hence $n$ floating-point values.

The Hermitian adjoint of $f$ is obtained in FFT representation by simply computing the conjugate
of each $f(\zeta)$, i.e. negating the imaginary part. This means that when a polynomial is equal to
its Hermitian adjoint (e.g. $ff^* + gg^*$), then its FFT representation contains only real values.

In Falcon, since the input polynomials are real, this Hermitian property is directly exploited. The second half of the spectrum is simply the complex conjugate of the first half, so only $n$/2 complex values must be computed and stored. This reduces both computation and storage requirements by approximately half compared to a conventional complex FFT. This property is clearly described in the Falcon specification and reflected in the original fft.c implementation provided by the Falcon team. Finally, in main.cpp, a simple verification test is included to compare polynomial multiplication results obtained using the classical schoolbook method and the FFT-based method.
