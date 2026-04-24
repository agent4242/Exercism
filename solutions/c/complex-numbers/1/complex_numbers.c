#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    complex_t number;
    number.real = a.real + b.real;
    number.imag = a.imag + b.imag;
    return number;
}

complex_t c_sub(complex_t a, complex_t b)
{
    complex_t number;
    number.real = a.real - b.real;
    number.imag = a.imag - b.imag;
    return number;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t number;
    number.real = (a.real * b.real) - (a.imag * b.imag);
    number.imag = (a.imag * b.real) + (a.real * b.imag);
    return number;
}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t number;
    number.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    number.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return number;
}

double c_abs(complex_t x)
{
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x)
{
    complex_t number;
    number.real = x.real;
    number.imag = (-1) * x.imag;
    return number;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t number;
    number.real = exp(x.real) * cos(x.imag);
    number.imag = exp(x.real) * sin(x.imag);
    return number;
}
