#include "display/gui.h"
#include "world/map.h"
#include "entities/fish.h"

int main(int argc, char ** argv){
    display::init_gui();
    world::map::init();
    entities::Fish my_fish(64, 32, 1, 0.14);
    entities::fishes.push_back(my_fish);
    display::loop();
    display::destroy_gui();
    world::map::destroy();
    return 0;
}