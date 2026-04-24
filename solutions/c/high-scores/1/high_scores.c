#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len-1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t max = 0;
    int i;

    for (i=0; i < (int) scores_len - 1; i++) {

        if (max < scores[i]) {
            max = scores[i];
        }
    }

    return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    int i;
    int j;
    int32_t temp;
    int32_t arr[(int) scores_len];

    if (scores_len == 1) {
        *output = *scores;
        return 1;            
    }

    if (scores_len == 2) {
        if (scores[0] < scores[1]) {
            output[0] = scores[1];
            output[1] = scores[0];
        } else {
            memcpy (output, scores, 2 * sizeof (int32_t));
        }

        return 2;
    }

    memcpy(arr, scores, scores_len * sizeof(int32_t));

    for (i=0; i < (int) scores_len-1; i++) {
        for (j=i+1; j < (int) scores_len; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(i=0; i<3; i++) {
        output[i] = arr[i];
    }
    
    return 3;    
    
    
}