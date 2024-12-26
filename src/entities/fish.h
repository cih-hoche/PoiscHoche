#ifndef FISH_H
#define FISH_H
#include <cstdint>
#include <string>
#include <vector>
#include <utility>

#include <SDL2/SDL_image.h>

namespace entities
{
    class Fish
    {
    public:
        float x, y;
        uint8_t width, height;
        double direction; // radians
        float speed;

        void tick(); // appelé à chaque frame
        void draw(SDL_Renderer *renderer, int offset_x, int offset_y);
        Fish(float _x, float _y, float _speed = 0.017, float _direction = 0, uint8_t _width = 32, uint8_t _height = 64);
    };

    extern std::vector<Fish> fishes;
}

#endif // FISH_H
