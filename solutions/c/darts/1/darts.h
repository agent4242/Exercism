#ifndef DARTS_H
#define DARTS_H
#include <stdint.h>
#define MISS 0
#define OUTTER 1
#define MIDDLE 5
#define INNER 10

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t pos);

#endif
