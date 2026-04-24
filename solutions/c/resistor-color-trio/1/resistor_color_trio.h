#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <math.h>

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef struct {
    int value;
    int unit;
} resistor_value_t;

enum {
    OHMS = 1,
    KILOOHMS = 2,
    MEGAOHMS = 3,
    GIGAOHMS = 4,
};

resistor_value_t color_code(resistor_band_t *colors);

#endif
