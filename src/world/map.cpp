#include "map.h"
#include "block.h"
#include <random>

namespace world::map {
    uint16_t height{256}, width{256};
    world::Block * * blocks{nullptr};

    void init(){
        world::init_blocks();
        world::map::blocks = (world::Block * *)malloc(sizeof(Block *) * width * height);
        for(int y = 0; y < height; y++)
            for(int x = 0; x < width; x++)
                if(rand() % 8 == 0) world::map::blocks[y*width + x] = world::blocks[1];
                else world::map::blocks[y*width + x] = world::blocks[0];
    }

    void destroy(){
        free(blocks);
        world::destroy_blocks();
    }
}