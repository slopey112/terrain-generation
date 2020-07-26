#include "types.h"
#include "heightmap.h"
#include <stdlib.h>
#include <stdio.h>

float noise;

float average_point(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], int x, int y, int width)
{
    int i = 0;
    float total = 0;
    if ((x + width) < SCREEN_WIDTH)
    {
        total += height_map[y][x + width];
        i++;
    }
    if ((x - width) > -1)
    {
        total += height_map[y][x - width];
        i++;
    }
    if ((y + width) < SCREEN_HEIGHT)
    {
        total += height_map[y + width][x];
        i++;
    }
    if ((y - width) > -1)
    {
        total += height_map[y - width][x];
        i++;
    }
    return total / i;
}

float random_float(int min, int max)
{
    return (float) rand() / (float) (RAND_MAX / max) + min;
}

void generate_heights(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], int x1, int y1, int x2, int y2)
{
    // TODO: refractor into breadth first
    // return condition;
    if (x2 - x1 == 1)
        return;

    float average;
    int midpoint_x, midpoint_y;
    int width = ((x2 - x1) / 2);

    // Average all four corners 
    average = (height_map[y1][x1] + height_map[y1][x2] + height_map[y2][x1] + height_map[y2][x2]) / 4;

    // Get new midpoint
    midpoint_x = ((x2 - x1) / 2) + x1;
    midpoint_y = ((y2 - y1) / 2) + y1;
    height_map[midpoint_y][midpoint_x] = average;
    
    // get average for each new square
    height_map[y1][midpoint_x] = average_point(height_map, midpoint_x, y1, width) + random_float(noise - noise / 2, noise);
    height_map[midpoint_y][x2] = average_point(height_map, x2, midpoint_y, width) + random_float(noise - noise / 2, noise);
    height_map[y2][midpoint_x] = average_point(height_map, midpoint_x, y2, width) + random_float(noise - noise / 2, noise);
    height_map[midpoint_y][x1] = average_point(height_map, x1, midpoint_y, width) + random_float(noise - noise / 2, noise);

    // recursive search
    generate_heights(height_map, x1, y1, midpoint_x, midpoint_y);
    generate_heights(height_map, midpoint_x, y1, x2, midpoint_y);
    generate_heights(height_map, x1, midpoint_y, midpoint_x, y2);
    generate_heights(height_map, midpoint_x, midpoint_y, x2, y2);


}

void generate_height_map(float height_map[SCREEN_HEIGHT][SCREEN_WIDTH], unsigned int seed, float seed_noise, float map_noise)
{
    noise = map_noise;
    srand(seed);
    height_map[0][0] = random_float(0, seed_noise);
    height_map[0][SCREEN_WIDTH - 1] = random_float(0, seed_noise);
    height_map[SCREEN_HEIGHT - 1][0] = random_float(0, seed_noise);
    height_map[SCREEN_HEIGHT - 1][SCREEN_WIDTH - 1] = random_float(0, seed_noise);

    generate_heights(height_map, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);

}

