#ifndef FIBULA_DRAWABLE_HPP
#define FIBULA_DRAWABLE_HPP

#include <Fibula/Graphics/RendererProvider.hpp>

namespace Fibula {
    namespace Graphics {
        class Drawable : public RendererProvider
        {
        public:
            virtual void draw()
            { }

            virtual void draw(SDL_Renderer *renderer = nullptr) = 0;
            virtual void cleanUp(SDL_Renderer *renderer = nullptr) = 0;
        };
    }
}


#endif //FIBULA_DRAWABLE_HPP
