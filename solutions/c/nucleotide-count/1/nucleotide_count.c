#include "nucleotide_count.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *count(const char *dna_strand){
    if (dna_strand == NULL) return NULL;
    
    int A = 0;
    int C = 0;
    int G = 0;
    int T = 0;
    int length = strlen(dna_strand);
    char *count = malloc(50);

    for (int i = 0; i < length; i++) {
        switch (dna_strand[i]) {
            case 'A':
                A++;
                break;
            case 'C':
                C++;
                break;
            case 'G':
                G++;
                break;
            case 'T':
                T++;
                break;
            default:
                count[0] = '\0';
                return count;
        }
    }
    
    sprintf(count, "A:%i C:%i G:%i T:%i", A, C, G, T);

    return count;
}
