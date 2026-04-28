#include "protein_translation.h"
#include <string.h>

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
                        protein.amino_acids[protein.count++] = Methionine;
                        codon_start += 3;
                        continue;
                    }
                }
                protein.valid = false;
                return protein;
            case 'U':
                switch (rna[codon_start+1]) {
                    case 'U':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                protein.amino_acids[protein.count++] = Phenylalanine;
                                codon_start += 3;
                                continue;
                            case 'A':
                            case 'G':
                                protein.amino_acids[protein.count++] = Leucine;
                                codon_start += 3;
                                continue;
                            default:
                                protein.valid = false;
                                return protein;
                        }
                    case 'C':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                            case 'A':
                            case 'G':
                                protein.amino_acids[protein.count++] = Serine;
                                codon_start += 3;
                                continue;
                            default:
                                protein.valid = false;
                                return protein;
                        }
                    case 'A':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                protein.amino_acids[protein.count++] = Tyrosine;
                                codon_start += 3;
                                continue;
                            case 'A':
                            case 'G':
                                return protein;
                            default:
                                protein.valid = false;
                                return protein;
                        }
                    case 'G':
                        switch (rna[codon_start+2]) {
                            case 'U':
                            case 'C':
                                protein.amino_acids[protein.count++] = Cysteine;
                                codon_start += 3;
                                continue;
                            case 'G':
                                protein.amino_acids[protein.count++] = Tryptophan;
                                codon_start += 3;
                                continue;
                            case 'A':
                                return protein;
                            default:
                                protein.valid = false;
                                return protein;
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