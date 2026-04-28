#include "protein_translation.h"

#include <string.h>

#define iscodon(A) ((i+2>=len) ? false : strncmp(&rna[i], A, 3)==0)
#define addcodon(A) protein.amino_acids[protein.count++] = A;

protein_t protein(const char *const rna){
    protein_t protein;
    protein.count = 0;
    protein.valid = true;
    int len = strlen(rna);

    for (int i = 0; i < len; i += 3){
        if (iscodon("AUG")){
            addcodon(Methionine);            
        } else if (iscodon("UUU") || iscodon("UUC")) {
            addcodon(Phenylalanine);
        } else if (iscodon("UUA") || iscodon("UUG")) {
            addcodon(Leucine);
        } else if (iscodon("UCU") || iscodon("UCC") || iscodon("UCA") || iscodon("UCG")) {
            addcodon(Serine);
        } else if (iscodon("UAU") || iscodon("UAC")) {
            addcodon(Tyrosine);
        } else if (iscodon("UGU") || iscodon("UGC")) {
            addcodon(Cysteine);
        } else if (iscodon("UGG")) {
            addcodon(Tryptophan);
        } else if (iscodon("UAA") || iscodon("UAG") || iscodon("UGA")) {
            return protein;
        } else {
            protein.valid = false;
            return protein;
        }
    }
    return protein;
}