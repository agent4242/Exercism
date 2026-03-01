#include "collatz_conjecture.h"

int steps(int start){
    int steps=0;

    if (start < 1) {
        return ERROR_VALUE;
    }
    
    while (1) {
        if (start%2==0) {
            start = start/2;
        } else if (start==1) {
            break;
        } else {
            start = start*3 + 1;
        }
        steps++;
    }
    return steps;
}
