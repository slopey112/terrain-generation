#include "types.h"
#include "heightmap.h"
#include "color.h"

#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{
    int running = 1;
    float height_map[SCREEN_HEIGHT][SCREEN_WIDTH];
    Color color_map[SCREEN_HEIGHT][SCREEN_WIDTH];

    generate_height_map(height_map);
    generate_color_map(height_map, color_map);

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            Color color = color_map[i][j];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }

    SDL_RenderPresent(renderer);
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
        }
    }
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}



