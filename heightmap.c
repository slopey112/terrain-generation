#include "types.h"
#include "heightmap.h"

void generate_heights(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], int x1, int y1, int x4, int y4)
{
    int x2, y2;
    int x3, y3;
    float average;
    int midpoint_x, midpoint_y;
    
    // Get the other two corners' x and y values.
    x2 = x1;
    y2 = y4;
    x3 = x2;
    y3 = y1;

    // Average all four corners 
    average = (height_map[y1][x1] + height_map[y2][x2] + height_map[y3][x3] + height_map[y4][x4]) / 4;

    // Get new midpoint
    midpoint_x = x4 / 2;
    midpoint_y = y4 / 2;

    // Generate 4 new squares
    height_map[midpoint_y][midpoint_x] = average;

    // Search new squares
    generate_heights(height_map, x1, y1, midpoint_x, midpoint_y);
    generate_heights(height_map, midpoint_x, y1, x4, midpoint_y);
    generate_heights(height_map, x1, midpoint_y, midpoint_x, y4);
    generate_heights(height_map, midpoint_x, midpoint_y, x4, y4);
}

void generate_height_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH])
{
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            height_map[i][j] = 0;
        }
    }
}

