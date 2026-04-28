#include "beer_song.h"

#include <stdio.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song){
    int verse_count = 0;

    uint8_t final_beer = start_bottles - (take_down - 1);
    
    for (int i = start_bottles; i >= final_beer; i--) {
        if (i>1) {
            sprintf(song[verse_count++], "%i bottles of beer on the wall, %i bottles of beer.", i, i);
            if (i==2) {
                sprintf(song[verse_count++], "Take one down and pass it around, 1 bottle of beer on the wall.");
            } else {
                sprintf(song[verse_count++], "Take one down and pass it around, %i bottles of beer on the wall.", i-1);
            } 
        } else if (i==1) {
            sprintf(song[verse_count++], "1 bottle of beer on the wall, 1 bottle of beer.");
            sprintf(song[verse_count++], "Take it down and pass it around, no more bottles of beer on the wall.");
        } else if (i==0) {
            sprintf(song[verse_count++], "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(song[verse_count++], "Go to the store and buy some more, 99 bottles of beer on the wall.");
        }
        verse_count++;
    }    
}