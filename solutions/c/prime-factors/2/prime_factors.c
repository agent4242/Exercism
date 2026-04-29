#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    size_t count = 0, increment = 0;
    
    while (n%2 == 0) {
        n /= 2;
        factors[count++] = 2;        
    }
    
    while (n != 1) {
        if (n%(3+increment) == 0) {
            n /= 3+increment;
            factors[count++] = 3+increment;
        } else {
            increment += 2;
        }
    }

    return count;
}