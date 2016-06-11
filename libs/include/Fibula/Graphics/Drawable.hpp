#pragma once

#include <SDL2/SDL.h>

namespace Fibula {
    namespace Graphics {
        class Drawable
        {
        public:
            virtual void draw(SDL_Renderer *renderer = nullptr) = 0;
            virtual void cleanUp(SDL_Renderer *renderer = nullptr) = 0;
        };
    }
}
