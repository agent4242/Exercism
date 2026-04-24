#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    int can = candidate;
    int i;
    int *arr = malloc(sizeof(int));
    int sum=0;
    int length=0;

    if (candidate == 0) {
        return true;
    }
    
    while (1) {
        arr = realloc(arr, (length+1) * sizeof(int));
        if (can%10 == 0) {}
        arr[length] = can%10;
        length++;
        can /= 10;

        if (can == 0) break;
    }
    
    for (i=0; i < length; i++) {

        sum += (int) pow(arr[i], length);
    }

    free(arr);
    
    return sum == candidate;    
    
}