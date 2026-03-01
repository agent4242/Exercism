#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    float age;
    
    switch(planet) {
        case MERCURY:
            age = ((float) seconds / 0.2408467F) / 31557600;
            break;
        case VENUS:
            age = ((float) seconds / 0.61519726F) / 31557600;
            break;
        case EARTH:
            age = ((float) seconds / 1) / 31557600;
            break;
        case MARS:
            age = ((float) seconds / 1.8808158F) / 31557600;
            break;
        case JUPITER:
            age = ((float) seconds / 11.862615F) / 31557600;
            break;
        case SATURN:
            age = ((float) seconds / 29.447498F) / 31557600;
            break;
        case URANUS:
            age = ((float) seconds / 84.016846F) / 31557600;
            break;
        case NEPTUNE:
            age = ((float) seconds / 164.79132F) / 31557600;
            break;
        default:
            return -1;
    }

    return age;
}