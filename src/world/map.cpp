#include "map.h"
#include "block.h"
#include <random>

namespace world::map {
    uint16_t height{256}, width{256};
    Block * * blocks{nullptr};

    void init(){
        init_blocks();
        blocks = static_cast<Block * *>(malloc(sizeof(Block *) * width * height));
        for(int y = 0; y < height; y++)
            for(int x = 0; x < width; x++)
                if(rand() % 20 == 0) blocks[y*width + x] = world::blocks[1];
                else blocks[y*width + x] = world::blocks[0];
    }

    void destroy(){
        free(blocks);
        destroy_blocks();
    }
}