#pragma once

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/Texture.hpp>
#include <Fibula/Graphics/Transformable.hpp>

namespace Fibula {
    namespace Graphics {
        class Sprite : public Drawable, public Transformable
        {
        protected:
            Texture *texture;
        public:
            Sprite(Texture *texture) : texture(texture)
            { }

            virtual ~Sprite()
            { }
        };
    }
}
