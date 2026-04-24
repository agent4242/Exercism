#include "triangle.h"

bool is_equilateral(triangle_t triangle) {
    if (triangle.a == 0) return false;
    return (triangle.a == triangle.b) && (triangle.b == triangle.c);
}

bool is_isosceles(triangle_t triangle) {
    if ((triangle.a == triangle.b && triangle.a + triangle.b >= triangle.c) ||
        (triangle.b == triangle.c && triangle.b + triangle.c >= triangle.a) ||
        (triangle.c == triangle.a && triangle.c + triangle.a >= triangle.b)) return true;

    return false;
}

bool is_scalene(triangle_t triangle) {
    if ((triangle.a != triangle.b && triangle.b != triangle.c && triangle.c != triangle.a) && 
        (fmin(triangle.a, triangle.b) + (fmin(triangle.b, triangle.c)) >= 
         fmax(fmax(triangle.a, triangle.b), fmax(triangle.b, triangle.c)))) return true;

    return false;
}