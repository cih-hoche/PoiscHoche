#include "offset.h"
#include "../world/map.h"

namespace display {
    void Offset::set(int _x, int _y) {
        x = _x;
        y = _y;
        x_blocks = (int) x / BLOCK_HW;
        y_blocks = (int) y / BLOCK_HW;
    }

    void Offset::setx(int _x) {
        x = _x;
        x_blocks = (int) x / BLOCK_HW;
    }

    void Offset::sety(int _y) {
        y = _y;
        y_blocks = (int) y / BLOCK_HW;
    }
}
