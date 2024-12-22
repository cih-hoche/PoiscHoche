#include "block.h"
#include "../display/gui.h"
#include <SDL2/SDL_image.h>
#include <string>
#include <utility>

namespace world {
    Block *blocks[256];

    Block::Block(std::string _name, const char *path, uint8_t _id, bool _collision): name(std::move(_name)),
        collision(_collision), id(_id) {
        surface = IMG_Load(path);

        if (surface == nullptr) {
            printf("world::Block::Block(): chargement de '%s' impossible\n---> %s\n", path, IMG_GetError());
        } else {
            // texture = SDL_CreateTextureFromSurface(display::renderer, surface);

            texture = SDL_CreateTexture(display::renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, BLOCK_HW,
                                        BLOCK_HW);
            SDL_SetRenderTarget(display::renderer, texture);
            if (id == 1) {
                SDL_SetRenderDrawColor(display::renderer, 0, 0, 0, 255);
            } else {
                SDL_SetRenderDrawColor(display::renderer, 255, 255, 255, 255);
            }

            SDL_Rect _rect = {0, 0, 2, 2};
            SDL_RenderFillRect(display::renderer, &_rect);
            _rect = {2, 2, 2, 2};
            SDL_RenderFillRect(display::renderer, &_rect);

            SDL_SetRenderTarget(display::renderer, nullptr);

            printf("world::Block::Block(): '%s' a été chargé\n", path);
        }
    }

    Block::~Block() {
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void init_blocks() {
        IMG_Init(0);
        // TODO Ne surtout pas garde comme ça
        blocks[0] = new Block("Eau", "../assets/water_0.png", 0, false);
        blocks[1] = new Block("Eau", "../assets/water_0.png", 0, false);
        blocks[2] = new Block("Eau", "../assets/water_0.png", 0, false);
        blocks[3] = new Block("Eau", "../assets/water_0.png", 0, false);
        blocks[4] = new Block("Pierre", "../assets/stone_0.png", 1);
    }

    void destroy_blocks() {
        /* TODO */
        delete blocks[0];
        delete blocks[1];
    }
}
