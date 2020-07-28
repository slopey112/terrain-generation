#include "color.h"
#include "types.h"
#include <stdio.h>

float clamp(float ratio)
{
    if (ratio > 1.0f)
        return 1.0f;
    else if (ratio < 0.0f)
        return 0.0f;
    return ratio;
}

unsigned char channel_interpolate(unsigned char a, unsigned char b, float ratio)
{
    return (unsigned char) a + (b - a) * ratio;
}

Color *color_interpolate(Color *from, Color *to, float ratio)
{
    ratio = clamp(ratio);
    // Cr = Ar + (Br - Ar) * t
    unsigned char new_r = channel_interpolate(from->r, to->r, ratio);
    unsigned char new_g = channel_interpolate(from->g, to->g, ratio);
    unsigned char new_b = channel_interpolate(from->b, to->b, ratio);
    return init_color(new_r, new_g, new_b);
}

void generate_color_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], Color color_map[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    Color *LOW_COLOR = init_color(255, 255, 255);
    Color *HIGH_COLOR = init_color(0, 0, 0);
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            Color *color = color_interpolate(LOW_COLOR, HIGH_COLOR, height_map[i][j] / MAX_ALTITUDE);
            color_map[i][j] = *color;
        }
    }
}


