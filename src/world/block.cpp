#include "block.h"
#include "../display/gui.h"
#include <SDL2/SDL_image.h>
#include <string>
#include <utility>

namespace world {
    Block * blocks[256];

    Block::Block(std::string _name, const char * path, uint8_t _id, bool _collision):
        name(std::move(_name)), collision(_collision), id(_id){
        surface = IMG_Load(path);
        if(surface == nullptr){
            printf("world::Block::Block(): chargement de '%s' impossible\n---> %s\n", path, IMG_GetError());
        } else {
            texture = SDL_CreateTextureFromSurface(display::renderer, surface);
            printf("world::Block::Block(): '%s' a été chargé\n", path);
        }
    }

    Block::~Block(){
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void init_blocks(){
        IMG_Init(0);
        blocks[0] = new Block("Eau", "./assets/water_0.png", 0, false);
        blocks[1] = new Block("Pierre", "./assets/stone_0.png", 1);
    }

    void destroy_blocks(){
        /* TODO */
        delete blocks[0];
        delete blocks[1];
    }
}
