#include "offset.h"

namespace display{
    void Offset::set(int _x, int _y){
        x = _x;
        y = _y;
        x_blocks = (int) x/16;
        y_blocks = (int) y/16;
    }
    void Offset::setx(int _x){
        x = _x;
        x_blocks = (int) x/16;
    }
    void Offset::sety(int _y){
        y = _y;
        y_blocks = (int) y/16;
    }
}
