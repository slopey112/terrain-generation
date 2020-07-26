#include "types.h"
#include <stdlib.h>

Color *init_rgb_color(unsigned char r, unsigned char g, unsigned char b)
{
    Color *color = malloc(sizeof(Color));
    color->r = r;
    color->g = g;
    color->b = b;
    return color;
}
