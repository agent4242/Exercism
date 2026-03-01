#include "darts.h"

uint8_t score(coordinate_t pos){

    if ((pos.x*pos.x + pos.y*pos.y) > 100) {
        return MISS;
        }

    if ((pos.x*pos.x + pos.y*pos.y) > 25) {
        return OUTTER;
        }

    if ((pos.x*pos.x + pos.y*pos.y) > 1) {
        return MIDDLE;
        } else {
        return INNER;
        }
}
