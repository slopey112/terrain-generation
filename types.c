#include "types.h"
#include <stdlib.h>
#include <stdio.h>

Color *init_color(unsigned char r, unsigned char g, unsigned char b)
{
    Color *color = malloc(sizeof(Color));
    color->r = r;
    color->g = g;
    color->b = b;
    return color;
}

void puts_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
            printf("%15f ", height_map[i][j]);
        puts("");
    }
}
