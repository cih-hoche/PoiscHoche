#ifndef POISCHOCHE_MAP_H
#define POISCHOCHE_MAP_H

#include "block.h"

namespace world::map {
    extern uint16_t height, width;

    extern world::Block * * blocks;

    void init();
    void destroy();
}


#endif //POISCHOCHE_MAP_H
