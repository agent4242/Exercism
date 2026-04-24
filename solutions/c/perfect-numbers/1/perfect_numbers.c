#include "perfect_numbers.h"

int classify_number(int num){
    int i;
    int sum = 1;

    if (num <= 0) {
        return ERROR;
    }

    if (num == 1) {
        return DEFICIENT_NUMBER;
    }

    for (i=2; i<=num/2; i++) {

        if (num%i == 0) {
            sum += i;
        }
        
    }

    if (sum == num) {
        return PERFECT_NUMBER;
    } else if (sum > num) {
        return ABUNDANT_NUMBER;
    } else {
        return DEFICIENT_NUMBER;
    }
    
}
