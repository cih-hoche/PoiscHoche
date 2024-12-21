#include "display/gui.h"
#include "world/map.h"

int main(int argc, char ** argv){
    display::init_gui();
    world::map::init();
    display::loop();
    display::destroy_gui();
    world::map::destroy();
    return 0;
}