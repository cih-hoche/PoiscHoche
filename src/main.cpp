#include "iostream"
#include "display/gui.h"
#include "world/map.h"

int main(int argc, char ** argv){
    world::map::init();
    display::init_gui();
    display::loop();
    display::destroy_gui();
    world::map::destroy();
    return 0;
}