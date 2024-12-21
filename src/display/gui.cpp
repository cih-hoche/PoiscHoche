#include "gui.h"
#include "offset.h"
#include "../world/map.h"

#define MIN(a,b) (a<=b?a:b)

namespace display {
    SDL_Window * window{nullptr};
    SDL_Renderer * renderer{nullptr};
    SDL_Event event;
    bool should_run{true};
    SDL_Texture * no_texture16x16;

    Offset offset;
    Offset window_size{800,450};

    void init_gui(){
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "display::init_gui(): initialisation de SDL2 échouée\n";
            printf("---> %s\n", SDL_GetError());
            exit(-1);
        }
        if((window = SDL_CreateWindow("PoiscHoche", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 450, SDL_WINDOW_RESIZABLE))
                   == nullptr){
            std::cout << "display::init_gui(): création de la fenêtre échouée\n";
            printf("---> %s\n", SDL_GetError());
            exit(-2);
        }

        window_size.set(800,450);

        if((renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE))
                     == nullptr){
            std::cout << "display::init_gui(): création du moteur de rendu échoué\n";
            printf("---> %s\n", SDL_GetError());
            exit(-3);
        }

        no_texture16x16 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET, 16, 16);
        SDL_SetRenderTarget(renderer, no_texture16x16);
        SDL_SetRenderDrawColor(renderer, 127, 0, 255, 255);
        SDL_Rect _rect = {0, 0, 8, 8};
        SDL_RenderFillRect(renderer, &_rect);
        _rect = {8, 8, 8, 8};
        SDL_RenderFillRect(renderer, &_rect);
        SDL_SetRenderTarget(renderer, nullptr);
    }

    void destroy_gui(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    void loop(){
        SDL_Point mouse_offset, old_offset;
        bool mousedown{false};

        while(should_run) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        should_run = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        mouse_offset = {event.button.x, event.button.y};
                        old_offset.x = offset.x;
                        old_offset.y = offset.y;
                        mousedown = true;
                        break;
                    case SDL_MOUSEMOTION:
                        if(mousedown){
                            if(old_offset.x - event.motion.x + mouse_offset.x >= 0 &&
                                old_offset.x - event.motion.x + mouse_offset.x < 128*16 - window_size.x)
                                offset.setx(old_offset.x - event.motion.x + mouse_offset.x);
                            if(old_offset.y - event.motion.y + mouse_offset.y >= 0 &&
                               old_offset.y - event.motion.y + mouse_offset.y < 64*16 - window_size.y)
                                offset.sety(old_offset.y - event.motion.y + mouse_offset.y);
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        mousedown = false;
                        break;
                    case SDL_WINDOWEVENT:
                        if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                            window_size.set(event.window.data1, event.window.data2);
                        }
                        break;
                }
            }
            render_map();
            render_entities();
            SDL_RenderPresent(renderer);
        }
    }

    void render_map(){
        SDL_Rect block_rect{0,0,16,16};
        SDL_Texture * _texture;

        for(int y = 0; y < MIN(window_size.y_blocks + 2, 64 - offset.y_blocks); y++)
            for(int x = 0; x < MIN(window_size.x_blocks + 2, 128 - offset.x_blocks); x++){
                block_rect.x = 16*x - offset.x%16;
                block_rect.y = 16*y - offset.y%16;
                _texture = world::map::blocks[x+offset.x_blocks+(y+offset.y_blocks)*world::map::width]->texture;
                SDL_RenderCopy(renderer, (_texture == nullptr ? no_texture16x16 : _texture), NULL, &block_rect);
            }
    }

    void render_entities(){
        /* TODO */
    }

    void load_textures(){
        /* TODO */

    }
}