/**
 * @Author: jamil
 * @Date:   2021-02-18T07:48:49-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-27T21:40:42-06:00
 */



#ifndef __COMPLEX_MATH__
#define __COMPLEX_MATH__

typedef struct{
    double re;
    double imag;
} complex_n_t;

complex_n_t cadd(complex_n_t a, complex_n_t b);
complex_n_t csub(complex_n_t a, complex_n_t b);

#endif
