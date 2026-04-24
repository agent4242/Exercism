#include "luhn.h"

bool luhn(const char *num) {
    int i;
    int j = 0;
    int sum = 0;

    if (strlen(num) < 2) return false;
    if (strlen(num) == 2 && (num[0] == ' ' || num[1] == ' ')) return false;

    for (i = (int)strlen(num) - 1; i >= 0; i--) {

        if (num[i] == ' ') continue;
        if (num[i] < 48 || num[i] > 57) return false;
        
        j++;

        if (j%2==0) { // Checks if it's a number which needs to be doubled
            if ((num[i]-48)*2 > 9) { // Checks if said number goes into two digits
                sum += (num[i]-48)*2 - 9; // Removes 9, which equates to the process of removing 10 in order to get the                                                          last digit, and then adding 1 to account for the tens place.
            } else {
                sum += (num[i]-48)*2; // Just sets the double of the number
            }
        } else {
            sum += (num[i]-48); // Just sets the number
        }
    }

    if (sum%10 == 0) {
        return true;
    } else {
        return false;
    }
    
}
