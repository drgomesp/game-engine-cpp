#ifndef FIBULA_RENDERERPROVIDER_HPP
#define FIBULA_RENDERERPROVIDER_HPP

#include <SDL2/SDL_render.h>

namespace Fibula {
    namespace Graphics {
        class RendererProvider
        {
        public:
            SDL_Renderer *renderer;

            inline void setRenderer(SDL_Renderer *renderer)
            {
                this->renderer = renderer;
            }

            inline SDL_Renderer *getRenderer() const
            {
                return renderer;
            }

            inline bool knowsRenderer()
            {
                return this->renderer == NULL;
            }
        };
    }
}

#endif //FIBULA_RENDERERPROVIDER_HPP
