#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value){
    char *reverse = malloc((strlen(value)+1)*sizeof(char));

    for (int i = (int)strlen(value); i >= 0; i--) {
        reverse[(int)strlen(value) - i] = value[i-1];
    }
    return reverse;
}