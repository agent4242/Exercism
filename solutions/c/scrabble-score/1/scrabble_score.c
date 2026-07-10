#include "scrabble_score.h"
#include <ctype.h>

unsigned int score(const char *word){
    int i = 0;
    unsigned int score = 0;

    // Alphabetically arranged points for each letter
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    
    while (word[i] != '\0') {
        score += points[toupper(word[i]) - 'A'];
        i++;
    }

    return score;
}