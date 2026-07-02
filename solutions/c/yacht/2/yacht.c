#include "yacht.h"

int score(dice_t dice, category_t category){

    int score = 0;

    if (category >= ONES && category <= SIXES) {    // Resolving ONES to SIXES with the same logic
        for (int i = 0; i < 5; i++) {
                if (dice.faces[i] == (int)category + 1) score += 1;
            }
        score *= category + 1;
        return score;
    } else {    // Resolving the rest of the cases with a switch
        switch(category) {
            case FULL_HOUSE: {
                int first_num = 0, second_num = 0, temp_index = -1;
                
                for (int i = 0; i < 5; i++) {
                    if (dice.faces[0] == dice.faces[i]) {    // Count the times the first number comes up
                        first_num++;
                    } else {
                        if (temp_index == -1) {    // Setting the second number can only be done once, returning 0
                            temp_index = i;        // if it is attempted to do so again (since it implies a third
                        } else if (dice.faces[temp_index] != dice.faces[i]) {    // number, not possible with full
                            return 0;                                            // house)
                        }
                    } 
                    if (dice.faces[temp_index] == dice.faces[i]) {    // Count the times the second number comes up
                        second_num++;
                    }
                }

                // Check for a combination of 2 and 3 of the two numbers
                if ((first_num == 3 && second_num == 2) || (first_num == 2 && second_num == 3)) {
                    for (int i = 0; i < 5; i++) {
                        score += dice.faces[i];
                    }
                    return score;
                } else {
                    return 0;
                }
            }
            case FOUR_OF_A_KIND: {
                int first_num = 0, second_num = 0, temp_index = -1;
                
                for (int i = 0; i < 5; i++) {
                    if (dice.faces[0] == dice.faces[i]) {
                        first_num++;
                    } else {
                        if (temp_index == -1) {
                            temp_index = i;
                        } else if (temp_index != i) {    // Same check for a third number as in the previous case
                            return 0;
                        }
                    } 
                    if (dice.faces[temp_index] == dice.faces[i]) {
                        second_num++;
                    }
                } 

                if (first_num >= 4) {    // Greater than or equal to in case it is a yacht (still applicable)
                    score = 4 * dice.faces[0];
                    return score;
                } else if (second_num == 4) {
                    score = 4 * dice.faces[temp_index];
                    return score;
                } else {
                    return 0;
                }
            }
            case LITTLE_STRAIGHT: {    // Bitmask used to OR in bits according to the dice face value
                int bit_storage = 0;
                for (int i = 0; i < 5; i++) {
                    if (dice.faces[i] == 6) return 0;
                    bit_storage |= 1 << (dice.faces[i] - 1);
                }

                if (bit_storage == 31) {    // 31 signifies the bits 0 to 4 being occupied
                    return 30;
                } else {
                    return 0;
                }
            }
            case BIG_STRAIGHT: {    // Same method as above
                int bit_storage = 0;
                for (int i = 0; i < 5; i++) {
                    if (dice.faces[i] == 1) return 0;
                    bit_storage |= 1 << (dice.faces[i] - 1);
                }

                if (bit_storage == 62) {    // 62 signifies the bits 1 to 5 being occupied
                    return 30;
                } else {
                    return 0;
                }
            }
            case CHOICE:
                for (int i = 0; i < 5; i++) {
                    score += dice.faces[i];
                }
                return score;
            case YACHT: 
                for (int i = 0; i < 5; i++) {
                    if (dice.faces[0] != dice.faces[i]) {
                        return 0;
                    } 
                } 
                return 50;
            default:
                return 0;
        }
    }
}