#include "color.h"
#include "types.h"

void generate_color_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], Color color_map[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            Color *color = init_rgb_color(0, 255, 0);
            color_map[i][j] = *color;
        }
    }
}


