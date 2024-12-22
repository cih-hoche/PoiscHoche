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
            #ifdef PERF_BUILD
                texture = SDL_CreateTexture(display::renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, BLOCK_HW,
                                            BLOCK_HW);
                SDL_SetRenderTarget(display::renderer, texture);
                if (id == 1) {
                    SDL_SetRenderDrawColor(display::renderer, 0, 0, 0, 255);
                } else {
                    SDL_SetRenderDrawColor(display::renderer, 255, 255, 255, 255);
                }

                SDL_Rect _rect = {0, 0, BLOCK_HW/2, BLOCK_HW/2};
                SDL_RenderFillRect(display::renderer, &_rect);
                _rect = {BLOCK_HW/2, BLOCK_HW/2, BLOCK_HW/2, BLOCK_HW/2};
                SDL_RenderFillRect(display::renderer, &_rect);

                SDL_SetRenderTarget(display::renderer, nullptr);
            #else
                texture = SDL_CreateTextureFromSurface(display::renderer, surface);
            #endif

            printf("world::Block::Block(): '%s' a été chargé\n", path);
        }
    }

    Block::~Block() {
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void init_blocks() {
        IMG_Init(0);
        blocks[0] = new Block("Eau", "./assets/water_0.png", 0, false);
        blocks[1] = new Block("Pierre", "./assets/stone_0.png", 1);
    }

    void destroy_blocks() {
        /* TODO */
        delete blocks[0];
        delete blocks[1];
    }
}
