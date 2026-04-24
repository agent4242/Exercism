#include "pangram.h"

bool is_pangram(const char *sentence){

    if(sentence == NULL) {
        return false;
    }
    
    int counter = 0;
    int i;

    for (i=0; sentence[i] != '\0'; i++) {

        if (sentence[i] == ' ' || sentence[i] == '_') {
            continue;
        }

        char low = tolower(sentence[i]);

        counter |= 1 << (low - 'a');        
    }

    return counter == (1 << 26) - 1;
    
}
