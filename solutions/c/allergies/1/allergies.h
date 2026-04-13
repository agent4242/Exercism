#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
} allergen_t;

typedef struct {
   int count;
   bool allergens[8];
} allergen_list_t;

allergen_list_t get_allergens(int score);
bool is_allergic_to(int allergen, int score);

#endif
