#include "hamming.h"


int compute(const char *lhs, const char *rhs){
    int i;
    int ham=0;
    
    if (strlen(lhs) != strlen(rhs)) {
        return -1;
    }

    for (i=0; i < (int) strlen(lhs); i++) {
        if (lhs[i] != rhs[i]) {
            ham++;
        }
    }

    return ham;
}
