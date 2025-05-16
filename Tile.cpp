#include "Tile.h"

//constructor definition
Tile::Tile(int x, int y, int size, tile_type type) : x(x), y(y), size(size), type(type) {}

//function to get rectangle properties
SDL_FRect Tile::getrect() { return { static_cast<float>(x), static_cast<float>(y), static_cast<float>(size), static_cast<float>(size) }; }

// Render function definition
void Tile::render(SDL_Renderer* renderer)
{
    SDL_FRect rect = getrect();

    switch (type)
    {
    case Grass:
        SDL_SetRenderDrawColor(renderer, 99, 189, 72, 255);
        SDL_RenderFillRect(renderer, &rect);
        break;

    case Path:
        SDL_SetRenderDrawColor(renderer, 158, 126, 76, 255);
        SDL_RenderFillRect(renderer, &rect);
        break;
    }
}
