#include "dnd_character.h"

int ability(void){
    int rolls[4];
    int i;
    int j;
    int sum=0;

    for (i=0; i<4; i++) {
        rolls[i] = 1 + rand() % 6;
    }

    for (i=0; i<3; i++){
        for (j=1; j<4; j++) {
            if (rolls[i] > rolls[j]) {
                int temp = rolls[i];
                rolls[i] = rolls[j];
                rolls[j] = temp;
            }
        }
    }

    for (i=1; i<4; i++) {
        sum += rolls[i]; 
    }
    
    return sum;
}

// STILL TO DO:

int modifier(int score){
    if (score<10 && score%2!=0) {
        return (score-10)/2 - 1;
    }
    return (score-10)/2;
}
dnd_character_t make_dnd_character(void){
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}