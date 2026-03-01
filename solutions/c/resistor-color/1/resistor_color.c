#include "resistor_color.h"

int color_code(resistor_band_t color) {
    return (int) color;
}

resistor_band_t *colors() {
    static resistor_band_t arr[] = {0, 1, 2 , 3, 4, 5, 6, 7, 8, 9};
    return arr;
} 