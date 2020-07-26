#ifndef TYPES_H
#define TYPES_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color *init_rgb_color(unsigned char r, unsigned char g, unsigned char b);

#endif
