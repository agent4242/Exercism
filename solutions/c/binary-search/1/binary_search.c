#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
    int min = 0;
    int max = length - 1;
    int mid;

    if (length < 3) {

        if (length == 0) {
            return NULL;
        }
        
        if (value == arr[0]) {
            return &arr[0];
        } else if (value == arr[1]) {
            return &arr[1];
        } else {
            return NULL;
        }
    }

    while (1) {

        mid = ((max-min)/2) + min;

        if (value == arr[mid]) {
            return &arr[mid];
        } else if (value < arr[mid]) {
            max = mid - 1;
        } else if (value > arr[mid]) {
            min = mid + 1;
        }

         if (min > max) {
            return NULL;
        }
        
    }
    

    
}
