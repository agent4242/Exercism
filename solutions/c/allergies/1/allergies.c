#include "allergies.h"

allergen_list_t get_allergens(int score){

    allergen_list_t list = {0}; // Sets the count to 0; Sets all the allergens to false

    if (score>=256) { // Removes any multiple of 256
        score = score - 256 * (score/256);
    }

    if (score-128>=0) { // Check for cats
        score-=128;
        list.allergens[ALLERGEN_CATS] = true;
        list.count++;
    }

    if (score-64>=0) { // Check for pollen
        score-=64;
        list.allergens[ALLERGEN_POLLEN] = true;
        list.count++;
    }

    if (score-32>=0) { // Check for chocolate
        score-=32;
        list.allergens[ALLERGEN_CHOCOLATE] = true;
        list.count++;
    }

    if (score-16>=0) { // Check for tomatoes
        score-=16;
        list.allergens[ALLERGEN_TOMATOES] = true;
        list.count++;
    }

    if (score-8>=0) { // Check for strawberries
        score-=8;
        list.allergens[ALLERGEN_STRAWBERRIES] = true;
        list.count++;
    }

    if (score-4>=0) { // Check for shellfish
        score-=4;
        list.allergens[ALLERGEN_SHELLFISH] = true;
        list.count++;
    }

    if (score-2>=0) { // Check for peanuts
        score-=2;
        list.allergens[ALLERGEN_PEANUTS] = true;
        list.count++;
    }

    if (score-1>=0) { // Check for eggs
        score-=1;
        list.allergens[ALLERGEN_EGGS] = true;
        list.count++;
    }

    return list;
}

bool is_allergic_to(int allergen, int score){
    
    allergen_list_t list = get_allergens(score);

    return list.allergens[allergen];
}


