#include "protein_translation.h"
#include <string.h>

// This is your only and final warning to turn back. This should not exist. But it does. :)

#define nope \
    protein.valid = false; \
    return protein;

#define yup(A) \
    protein.amino_acids[protein.count++] = A; \
    codon_start += 3; \
    continue;

protein_t protein(const char *const rna){    
    protein_t protein;
    protein.valid = true;
    protein.count = 0;
    int codon_start = 0;

    while (rna[codon_start] != '\0') {
        switch (rna[codon_start]) {
            case 'A':
                if (rna[codon_start+1] == 'U') {
                    if (rna[codon_start+2] == 'G') {
                        yup(Methionine);
                    }
                }
                nope;
            case 'U':
                switch (rna[codon_start+1]) {
                    case 'U':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                yup(Phenylalanine);
                            case 'A':
                            case 'G':
                                yup(Leucine);
                            default:
                                nope;
                        }
                    case 'C':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                            case 'A':
                            case 'G':
                                yup(Serine);
                            default:
                                nope;
                        }
                    case 'A':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                yup(Tyrosine);
                            case 'A':
                            case 'G':
                                return protein;
                            default:
                                nope;
                        }
                    case 'G':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                yup(Cysteine);
                            case 'G':
                                yup(Tryptophan);
                            case 'A':
                                return protein;
                            default:
                                nope;
                        }
                    default:
                        protein.valid = false;
                        return protein;
                }
            default:
                protein.valid = false;
                return protein;
        }         
    }
    return protein;    
}