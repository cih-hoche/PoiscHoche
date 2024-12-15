#include "gui.h"
#include "../world/map.h"

namespace display {
    SDL_Window * window{nullptr};
    SDL_Renderer * renderer{nullptr};
    SDL_Event event;
    bool should_run{true};

    void init_gui(){
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cout << "display::init_gui(): initialisation de SDL2 échouée\n";
            exit(-1);
        }
        if((window = SDL_CreateWindow("PoiscHoche", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 450, SDL_WINDOW_RESIZABLE))
                   == nullptr){
            std::cout << "display::init_gui(): création de la fenêtre échouée\n";
            exit(-2);
        }
        if((renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE))
                     == nullptr){
            std::cout << "display::init_gui(): création du moteur de rendu échoué\n";
            exit(-3);
        }
    }

    void destroy_gui(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    void loop(){
        while(should_run) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        should_run = false;
                        break;
                }
            }
            render_map();
            render_entities();
            SDL_RenderPresent(renderer);
        }
    }

    void render_map(){
        /* TODO */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect block_rect{0,0,16,16};

        for(int y = 0; y < world::map::height; y++)
            for(int x = 0; x < world::map::width; x++){
                block_rect.x = 16*x;
                block_rect.y = 16*y;
                switch(world::map::blocks[x+y*world::map::width]->id){
                    case 0:
                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                        SDL_RenderFillRect(renderer, &block_rect);
                        break;
                    case 1:
                        SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
                        SDL_RenderFillRect(renderer, &block_rect);
                        break;
                }
            }
    }

    void render_entities(){
        /* TODO */
    }

    void load_textures(){
        /* TODO */

    }
}