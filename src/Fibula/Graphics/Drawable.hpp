#ifndef FIBULA_DRAWABLE_HPP
#define FIBULA_DRAWABLE_HPP

#include <Fibula/Graphics/RendererProvider.hpp>

namespace Fibula {
    namespace Graphics {
        class Drawable : public RendererProvider
        {
            virtual void draw() = 0;
            virtual void cleanUp() = 0;
        };
    }
}


#endif //FIBULA_DRAWABLE_HPP
