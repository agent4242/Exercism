#include "sieve.h"

#include <stdbool.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
       
    if (limit <= 1) return 0;
    
    primes[0] = 2;
    if (limit == 2) return 1;    

    uint32_t i;
    int j;
    int element = 1;
    int max_divisible_prime = 1;
    uint32_t number_of_primes = 2;
    bool not_prime = false;
    primes[1] = 3;

    for (i=5; i <= limit && number_of_primes < (uint32_t) max_primes; i += 2) {
        
        if (i == primes[max_divisible_prime] * primes[max_divisible_prime]) max_divisible_prime++;
        
        for (j = 1; j <= max_divisible_prime; j++) {
            if (i%primes[j] == 0) {
                not_prime = true;
                break;
            }     
        }

        if (not_prime) {
            not_prime = false;
            continue;
        }

        element++;
        primes[element] = i;
        number_of_primes++;
    }
    return number_of_primes;    
}