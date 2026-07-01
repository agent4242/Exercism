#include "all_your_base.h"

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {

    if (input_base < 2 || output_base < 2 || input_length < 1) return 0;
    
    int sum = 0;
    size_t output_length = 0;
    int8_t output_digits[DIGITS_ARRAY_SIZE];
    
    for (int i = input_length - 1; i >= 0 ; i-- ) { // Converting the input into a base 10 sum

        if (digits[i] >= input_base || digits[i] < 0) {
            return 0;
        }
        
        sum += digits[input_length - 1 - i] * pow(input_base, i); 
        
    }

    if (sum == 0 ) return 1;

    while (sum > 0) { // Converting the base 10 sum into a backward output

        output_digits[output_length++] = sum%output_base; 
        sum /= output_base; 
    }

    for (int i = 0; i < (int)output_length; i++) { // Converting backward output to forward output

        digits[i] = output_digits[output_length - 1 - i];
        
    }

    return output_length;
}