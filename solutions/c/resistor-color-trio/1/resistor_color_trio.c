#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *colors){
    resistor_value_t x;
    int rawvalue;
    int i;
    int exponent = colors[2];
    int prefix;

    if (colors[1] == BLACK) {
        exponent++; 
        rawvalue = colors[0];
    } else {
        rawvalue = colors[0] * 10 + colors[1];
    }

    if (exponent < 3) {
        x.value = rawvalue * (int) pow(10, exponent);
        x.unit = OHMS;

        return x;
    } else if (exponent == 3) {
        x.value = rawvalue;
        x.unit = KILOOHMS;
    }

    for (i=0; exponent >= 3; i++) {
        exponent -= 3;
    }

    x.value = rawvalue * (int) pow(10, exponent);

    prefix = colors[2] - exponent;

    switch (prefix) {
        case 3:
            x.unit = KILOOHMS;
            break;
        case 6:
            x.unit = MEGAOHMS;
            break;
        case 9:
            x.unit = GIGAOHMS;
            break;
    }
    
    return x;
    
}