/**
 * @Author: jamil
 * @Date:   2021-02-18T07:48:49-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-27T21:40:39-06:00
 */



#include "complex_math.h"
complex_n_t cadd(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re + b.re;
    res.imag = a.imag + b.imag;
    return res;
}


complex_n_t csub(complex_n_t a, complex_n_t b){
    complex_n_t res;
    res.re = a.re - b.re;
    res.imag = a.imag - b.imag;
    return res;
}
