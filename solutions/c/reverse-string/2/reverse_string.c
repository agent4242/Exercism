#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value){
    int length = strlen(value);
    char *reverse = malloc((length+1)*sizeof(char));

    for (int i = length; i > 0; i--) {
        reverse[length - i] = value[i-1];
    }
    reverse[length] = '\0';
    return reverse;
}