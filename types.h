#ifndef TYPES_H
#define TYPES_H

#define SCREEN_WIDTH 257
#define SCREEN_HEIGHT 257

#define MAX_ALTITUDE 1000
#define MIN_ALTITUDE 0

#define FLT_MIN -10000000.0f

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color *init_color(unsigned char r, unsigned char g, unsigned char b);
void puts_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH]);

#endif
