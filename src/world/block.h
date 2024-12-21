#ifndef POISCHOCHE_BLOCK_H
#define POISCHOCHE_BLOCK_H
#include <string>
#include <SDL2/SDL.h>

namespace world {
    class Block {
    private:
        SDL_Surface * surface;
    public:
        std::string name;
        bool collision;
        SDL_Texture * texture{nullptr};
        uint8_t id;

        explicit Block(std::string _name, const char * path, uint8_t _id, bool _collision=true);
        ~Block();
    };

    extern Block * blocks[256];

    void init_blocks();
    void destroy_blocks();
}


#endif //POISCHOCHE_BLOCK_H
