#include "fish.h"
#include <cmath>
#include "../world/block.h"
#define MIN(a,b) (a<=b?a:b)
#define MAX(a,b) (a<=b?b:a)

namespace entities {
    std::vector<Fish> fishes;

    void Fish::tick(){
        x += speed * (float) cos(direction);
        y += speed * (float) sin(direction);

        bool hasCollidedX{false}, hasCollidedY{false};

        unsigned int x_blocks = (int) MIN(x/BLOCK_HW - 1, 0);
        unsigned int x_blocks_end = (int) MAX((x + width)/BLOCK_HW + 1, 0);
        unsigned int y_blocks = (int) MIN(y/BLOCK_HW - 1, 0);
        unsigned int y_blocks_end = (int) MAX((y + height)/BLOCK_HW + 1, 0);
        for(unsigned int _y = y_blocks; _y <= y_blocks_end; _y++)
            for(unsigned int _x = x_blocks; _x <= x_blocks_end; _x++){
                /* TO FINISH */
            }
    }

    Fish::Fish(float _x, float _y, float _speed, float _direction, uint8_t _width, uint8_t _height):
      x(_x), y(_y), speed(_speed), direction(_direction), width(_width), height(_height){
    }
}