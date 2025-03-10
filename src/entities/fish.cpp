#include "fish.h"
#include <cmath>
#include "../world/block.h"
#include "../world/map.h"
#include "../display/gui.h"
#include <SDL2/SDL_image.h>


#define MIN(a, b) (a <= b ? a : b)
#define MAX(a, b) (a <= b ? b : a)

namespace entities {
    std::vector<Fish> fishes;

    Fish::Fish(float _x, float _y, float _speed, float _direction, uint8_t _width, uint8_t _height) : x(_x), y(_y),
        speed(_speed), direction(_direction), width(_width), height(_height) {
        const char *path = "./assets/fish.png";
        surface = IMG_Load(path);

        if (surface == nullptr) {
            printf("world::Block::Block(): chargement de '%s' impossible\n---> %s\n", path, IMG_GetError());
            texture = display::no_texture16x16;
        } else {
            texture = SDL_CreateTextureFromSurface(display::renderer, surface);
            printf("world::Block::Block(): '%s' a été chargé\n", path);
        }
    }

    void Fish::tick() {
        int rwidth = width * BLOCK_HW;
        int rheight = height * BLOCK_HW;
        // Check collision
        float tp_dir = direction;
        float tp_x = x + speed * static_cast<float>(cos(tp_dir));
        float tp_y = y + speed * static_cast<float>(sin(tp_dir));

        float x_topright = tp_x + cos(M_PI / 2 - direction) * (rheight / 2);
        int x_topright_blocks = static_cast<int>(x_topright / BLOCK_HW);
        float y_topright = tp_y - sin(M_PI / 2 - direction) * (rheight / 2);
        int y_topright_blocks = static_cast<int>(y_topright / BLOCK_HW);
        float x_bottomright = tp_x - cos(M_PI / 2 - direction) * (rheight / 2);
        int x_bottomright_blocks = static_cast<int>(x_bottomright / BLOCK_HW);
        float y_bottomright = tp_y + sin(M_PI / 2 - direction) * (rheight / 2);
        int y_bottomright_blocks = static_cast<int>(y_bottomright / BLOCK_HW);
        float x_topleft = x_topright - cos(direction) * rwidth;
        int x_topleft_blocks = static_cast<int>(x_topleft / BLOCK_HW);
        float y_topleft = y_topright - sin(direction) * rwidth;
        int y_topleft_blocks = static_cast<int>(y_topleft / BLOCK_HW);
        float x_bottomleft = x_bottomright - cos(direction) * rwidth;
        int x_bottomleft_blocks = static_cast<int>(x_bottomleft / BLOCK_HW);
        float y_bottomleft = y_bottomright - sin(direction) * rwidth;
        int y_bottomleft_blocks = static_cast<int>(y_bottomleft / BLOCK_HW);
        if (
            0 < y_topright_blocks &&
            0 < x_topright_blocks &&
            0 < y_topleft_blocks &&
            0 < x_topleft_blocks &&
            0 < y_bottomright_blocks &&
            0 < x_bottomright_blocks &&
            0 < y_bottomleft_blocks &&
            0 < x_bottomleft_blocks
        ) {
            if (!(world::map::blocks[y_topright_blocks * world::map::width + x_topright_blocks]->collision ||
                  world::map::blocks[y_topleft_blocks * world::map::width + x_topleft_blocks]->collision ||
                  world::map::blocks[y_bottomleft_blocks * world::map::width + x_bottomleft_blocks]->collision ||
                  world::map::blocks[y_bottomright_blocks * world::map::width + x_bottomright_blocks]->collision
            )) {
                x = tp_x;
                y = tp_y;
                direction = tp_dir;
            }
        }
    }

    void Fish::draw(SDL_Renderer *renderer, int offset_x, int offset_y) {
        int rwidth = width * BLOCK_HW;
        int rheight = height * BLOCK_HW;
        SDL_Rect rFish{(int) x - rwidth - offset_x, (int) y - (rheight / 2) - offset_y, rwidth, rheight};
        SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
        SDL_RenderFillRect(renderer, &rFish);

        SDL_Point rotationPoint{(int) width * BLOCK_HW, (int) height * BLOCK_HW / 2};
        SDL_RenderCopyEx(renderer, texture, nullptr, &rFish, direction * (180 / M_PI), &rotationPoint, SDL_FLIP_NONE);


        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        float x_topright = x + cos(M_PI / 2 - direction) * (rheight / 2);
        float y_topright = y - sin(M_PI / 2 - direction) * (rheight / 2);
        float x_bottomright = x - cos(M_PI / 2 - direction) * (rheight / 2);
        float y_bottomright = y + sin(M_PI / 2 - direction) * (rheight / 2);
        float x_topleft = x_topright - cos(direction) * rwidth;
        float y_topleft = y_topright - sin(direction) * rwidth;
        float x_bottomleft = x_bottomright - cos(direction) * rwidth;
        float y_bottomleft = y_bottomright - sin(direction) * rwidth;


        display::render_point(renderer, x_topright, offset_x, y_topright, offset_y);
        display::render_point(renderer, x_bottomright, offset_x, y_bottomright, offset_y);
        display::render_point(renderer, x_topleft, offset_x, y_topleft, offset_y);
        display::render_point(renderer, x_bottomleft, offset_x, y_bottomleft, offset_y);

        display::render_point(renderer, x, offset_x, y, offset_y);
    }
}
