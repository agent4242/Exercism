#include "nth_prime.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 536870912

uint32_t nth(uint32_t n) {
    if (n == 0) return 0;

    uint32_t count = 0;
    
    bool *isprime = malloc(MAX_INT);
    memset(isprime, 1, MAX_INT);
    
    for (uint32_t i = 2; i < MAX_INT; i++) {
        if (isprime[i]) {
            for (uint32_t j = i * 2; j < MAX_INT/2; j+=i) {
                isprime[j] = false;
            }
            count++;

            if (count == n) {
                return i;
            }
        }                
    }

    return 0;
}

