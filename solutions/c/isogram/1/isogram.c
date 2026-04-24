#include "isogram.h"

bool is_isogram(const char phrase[]){
    int i;
    int j;

    if (phrase == NULL) {
        return false;
    }
    
    if (phrase[0] == '\0') {
        return true;
    }

    for (i=0; i < (int) strlen(phrase)-1; i++) {
        for (j= i+1; j < (int) strlen(phrase); j++) {
            if (tolower(phrase[i]) == tolower(phrase[j]) && phrase[i] != '-' && phrase[i] != ' ') {
                return false;
            }
        }
    }

    return true;
}
