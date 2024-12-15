#include "block.h"
#include <string>
#include <utility>

namespace world {
    Block * blocks[256];

    Block::Block(std::string _name, SDL_Texture * _texture, uint8_t _id, bool _collision):
        name(std::move(_name)), texture(_texture), collision(_collision), id(_id){
    }

    void init_blocks(){
        /* TODO */
        blocks[0] = new Block("Eau", nullptr, 0, false);
        blocks[1] = new Block("Pierre", nullptr, 1, false);
    }

    void destroy_blocks(){
        /* TODO */
        delete blocks[0];
        delete blocks[1];
    }
}
