#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key){
    int i;
    char *newtext = malloc(strlen(text));

    for (i=0; i < (int) strlen(text); i++) {

        if (65 <= text[i] && text[i] <= 90) {
            if (shift_key + text[i] > 90) {
                newtext[i] = text[i]+shift_key - 90 + 64;
            } else {
                newtext[i] = text[i]+shift_key;
            }            
        } else if (97 <= text[i] && text[i] <= 122) {
            if (shift_key + text[i] > 122) {
                newtext[i] = text[i]+shift_key - 122 + 96;
            } else {
                newtext[i] = text[i]+shift_key;
            }            
        } else {
            newtext[i] = text[i];
        }

    }

    return newtext;    
}
