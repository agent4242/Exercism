#include "binary.h"

int convert(const char *input){

    int i;
    int sum = 0;
    int poweroftwo = 1;
    
    for (i = (int) strlen(input) - 1; i >= 0 ; i--) {
        if (input[i] != '1' && input[i] != '0' && input[i] != '\0') {
            return INVALID;
        }

        sum = sum + ((input[i] - '0') * poweroftwo);
        poweroftwo = poweroftwo * 2;
    }

    return sum;
    
}