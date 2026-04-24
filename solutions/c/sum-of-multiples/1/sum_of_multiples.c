#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    int i;
    int length = 1;
    unsigned int sum = 0;
    unsigned int multiple;
    unsigned int *arr = malloc(sizeof(unsigned int));
    arr[0] = 0;

    for (i=0; i < (int) number_of_factors; i++) {

        int j = 1;
        int x;
        bool repeat = false;

        for (x=0; x < length; x++) {
            if (factors[i] == arr[x]) {
                repeat = true;
                break;
            }
        }

        if (repeat) continue;

        while (1) {

            multiple = factors[i] * j;

            j++;

            if (multiple >= limit) break;

            for (x=0; x < length; x++) {

                if (multiple == arr[x]) {
                    repeat = true;
                    break;
                }                
            }

            if (repeat) {
                repeat = false;
                continue;
            }

            length++;
            arr = realloc(arr, length * sizeof(unsigned int));
            arr[length-1] = multiple;
            
        }        
        
    }

    for (i=0; i < length; i++) {
        sum += arr[i];
    }

    free(arr);
    
    return sum;
}