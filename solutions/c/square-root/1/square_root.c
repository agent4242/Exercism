#include "square_root.h"

int square_root(int num) {

    if (num == 1) return 1;

    int max = num/2;
    int min = 0;
    int temp = num/4;

    while (1) {
        if (temp * temp < num) {
            min = temp + 1;
            temp = (max-min)/2 + min;
        } else if (temp * temp > num) {
            max = temp - 1;
            temp = (max-min)/2 + min;
        } else if (temp * temp == num) {
            return temp;
        }
    }
}