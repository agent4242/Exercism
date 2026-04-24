#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit){

    unsigned int i;
    unsigned int sum = 0;
    int j;

    for (i=0; i < (unsigned int) limit; i++) {
        for (j=0; j < (int) number_of_factors; j++) {
            if (factors[j] == 0) continue;
            if (i % factors[j] == 0) {
                sum += i;
                break;
            }
        }
    }

    return sum;
}