#include "sieve.h"
#include <stdbool.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    bool isprime[limit];
    memset(isprime, 1, limit);
    int count = 0;
    for (uint32_t i = 2; i <= limit && count < (int)max_primes; i++) {
        if (isprime[i]) {
            for (uint32_t j = i * 2; j <= limit; j+=i) {
                isprime[j] = false;
            }
            primes[count] = i;
            count++;
        }        
    }
    return count;    
}
