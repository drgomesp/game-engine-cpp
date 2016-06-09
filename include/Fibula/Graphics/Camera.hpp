#pragma once

#include <SDL2/SDL_rect.h>

namespace Fibula {
    namespace Graphics {
        class Camera
        {
        protected:
            unsigned int id;
            SDL_Rect rectangle;

        public:
            Camera(unsigned int id, const SDL_Rect &rectangle) : id(id), rectangle(rectangle)
            { }
        };
    }
}
