#ifndef POISCHOCHE_GUI_H
#define POISCHOCHE_GUI_H
#include <SDL2/SDL.h>
#include <iostream>
#include "offset.h"


namespace display{
    extern SDL_Window * window;
    extern SDL_Renderer * renderer;
    extern SDL_Event event;
    extern SDL_Texture * no_texture16x16;

    extern bool should_run;
    extern Offset offset;
    extern Offset window_size;
    extern float zoom; //TODO

    void init_gui();
    void destroy_gui();
    void loop();
    void render_map();
    void render_entities();
    void load_textures();
}


#endif //POISCHOCHE_GUI_H
