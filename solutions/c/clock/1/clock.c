#include "clock.h"

clock_t clock_create(int hour, int minute) {
    clock_t clock;

    if (minute < 0) {
        hour += minute/60 - 1;
        minute = 60 + minute%60;
    }

    if (minute >= 60) {
        hour += minute/60;
        minute = minute%60;
    }

    if (hour >= 24) {
        hour = hour%24;
    }

    if (hour < 0) {
        hour = 24 + hour%24;
    }

    sprintf(clock.text, "%i%i:%i%i", hour/10, hour%10, minute/10, minute%10);

    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    int hour = (clock.text[0]-48)*10 + (clock.text[1]-48);
    int minute = (clock.text[3]-48)*10 + (clock.text[4]-48);
    
    if (minute_add + minute >= 60) {
        hour += (minute_add + minute)/60;
    }

     if (hour >= 24) {
        hour = hour%24;
    }

    minute = (minute_add + minute)%60;

    clock.text[0] = hour/10 + 48;
    clock.text[1] = hour%10 + 48;
    clock.text[3] = minute/10 + 48;
    clock.text[4] = minute%10 + 48;

    return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {

    int hour = (clock.text[0]-48)*10 + (clock.text[1]-48);
    int minute = (clock.text[3]-48)*10 + (clock.text[4]-48);
    
    if (minute - minute_subtract < 0) {
        hour += (minute - minute_subtract)/60 - 1;
        minute = 60 + (minute - minute_subtract)%60;
    } else {
        minute = (minute - minute_subtract)%60;
    }

     if (hour < 0) {
        hour = 24 + hour%(24);
        if (hour == 24) hour = 0;
    }


    clock.text[0] = hour/10 + 48;
    clock.text[1] = hour%10 + 48;
    clock.text[3] = minute/10 + 48;
    clock.text[4] = minute%10 + 48;
    
    return clock;
}

bool clock_is_equal(clock_t a, clock_t b) {

    bool same = false;
    
    if (strcmp(a.text, b.text) == 0) same = true; 

    return same;
    
}