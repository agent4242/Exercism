#include "grains.h"

uint64_t square(uint8_t index){
    if (index == 0) {
        return 0;
    }
    uint64_t i;
    uint64_t square = 1;
    for (i = 1; i < index; i++) {
        square = square * 2;
    }
    return square;    
}

uint64_t total(void) {
    return square(64)*2-1;
}
