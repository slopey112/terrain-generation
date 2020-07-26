#ifndef TYPES_H
#define TYPES_H

#define SCREEN_WIDTH 1025
#define SCREEN_HEIGHT 1025

#define MAX_ALTITUDE 100
#define MIN_ALTITUDE 0

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color *init_color(unsigned char r, unsigned char g, unsigned char b);

#endif
