#include "eliuds_eggs.h"

int egg_count(int eggs){

    int counter = 0;

    while (1) {

        if (eggs == 0) {
            return counter;
        }

        if (eggs % 2 != 0) {
            counter++;
            eggs /= 2;
        } else {
            eggs /= 2;
        }
        
    }
    
}
