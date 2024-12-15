#ifndef POISCHOCHE_GUI_H
#define POISCHOCHE_GUI_H
#include <SDL2/SDL.h>
#include <iostream>


namespace display{
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;
    extern SDL_Event event;
    extern bool should_run;

    void init_gui();
    void destroy_gui();
    void loop();
    void render_map();
    void render_entities();
    void load_textures();
}


#endif //POISCHOCHE_GUI_H
