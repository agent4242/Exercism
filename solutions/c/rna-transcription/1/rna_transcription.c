#include "rna_transcription.h"

char *to_rna(const char *dna){
    int i;
    char *rna = malloc(strlen(dna));
    
    if (dna[0] == '\0') {
        return rna;
    }
    
    for (i=0; i < (int) strlen(dna); i++) {

        switch (dna[i]) {
            case 'G':
                rna[i] = 'C';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            case 'A':
                rna[i] = 'U';
                break;
            default:
                break;
        }
    }
    return rna;
}
