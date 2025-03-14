#include "display/gui.h"
#include "world/map.h"
#include "entities/fish.h"

int main(int argc, char ** argv){
    display::init_gui();
    world::map::init();
    entities::Fish my_fish(128, 128, 2, 0, (uint8_t) 4, (uint8_t) 2);
    entities::fishes.push_back(my_fish);
    display::loop();
    display::destroy_gui();
    world::map::destroy();
    return 0;
}