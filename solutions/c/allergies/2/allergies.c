#include "allergies.h"

bool is_allergic_to(const allergen_t item, const uint32_t score){
    return ((1<<item) & score) > 0;     // Uses a bit mask to move the bit 1 in order to represent one of the allergen items,
}                                       // and then bit ADDs them in order to see if the score and the 1 bit occupy the same bit.


allergen_list_t get_allergens(const uint32_t score){
    allergen_list_t list = {0};

    for (allergen_t item = ALLERGEN_EGGS; item < ALLERGEN_COUNT; item++) {    // Uses is_allergic_to in order to go by each item
        list.allergens[item] = is_allergic_to(item, score);                   // one by one and set them as true or false.
        if (list.allergens[item]) list.count ++;
    }

    return list;
}