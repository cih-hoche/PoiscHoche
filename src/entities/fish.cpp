#include "fish.h"
#include <cmath>
#include "../world/block.h"
#include "../display/gui.h"
#include <SDL2/SDL_image.h>
#define MIN(a, b) (a <= b ? a : b)
#define MAX(a, b) (a <= b ? b : a)

namespace entities
{
    std::vector<Fish> fishes;
    Fish::Fish(float _x, float _y, float _speed, float _direction, uint8_t _width, uint8_t _height) : x(_x), y(_y), speed(_speed), direction(_direction), width(_width), height(_height)
    {
        const char *path = "./assets/fish.png";
        surface = IMG_Load(path);

        if (surface == nullptr)
        {
            printf("world::Block::Block(): chargement de '%s' impossible\n---> %s\n", path, IMG_GetError());
            texture = display::no_texture16x16;
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(display::renderer, surface);
            printf("world::Block::Block(): '%s' a été chargé\n", path);
        }
    }

    void Fish::tick()
    {
        direction += 0.001;
        x += speed * (float)cos(direction);
        y += speed * (float)sin(direction);

        bool hasCollidedX{false}, hasCollidedY{false};

        unsigned int x_blocks = (int)MIN(x / BLOCK_HW - 1, 0);
        unsigned int x_blocks_end = (int)MAX((x + width) / BLOCK_HW + 1, 0);
        unsigned int y_blocks = (int)MIN(y / BLOCK_HW - 1, 0);
        unsigned int y_blocks_end = (int)MAX((y + height) / BLOCK_HW + 1, 0);
        for (unsigned int _y = y_blocks; _y <= y_blocks_end; _y++)
            for (unsigned int _x = x_blocks; _x <= x_blocks_end; _x++)
            {
                /* TODO TO FINISH */
            }
    }

    void Fish::draw(SDL_Renderer *renderer, int offset_x, int offset_y)
    {   
        int rwidth = width * BLOCK_HW;
        int rheight = height * BLOCK_HW;
        SDL_Rect rFish{(int)x - rwidth - offset_x, (int)y - (rheight / 2) - offset_y, rwidth, rheight};
        SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
        SDL_RenderFillRect(renderer, &rFish);

        SDL_Point rotationPoint{(int) width * BLOCK_HW, (int) height * BLOCK_HW / 2};
        SDL_RenderCopyEx(renderer, texture, nullptr, &rFish, direction * (180 / M_PI), &rotationPoint, SDL_FLIP_NONE);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        int posRectS = 16;

        SDL_Rect positionPointRect = {((int)x - offset_x) - posRectS / 2, ((int)y - offset_y) - posRectS / 2, posRectS, posRectS};
        SDL_RenderFillRect(renderer, &positionPointRect);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawPointF(renderer, (int)x - offset_x, (int)y - offset_y);
    }

}