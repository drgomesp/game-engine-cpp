#pragma once

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/Texture.hpp>
#include <Fibula/Graphics/Transformable.hpp>

namespace Fibula {
    namespace Graphics {
        class Sprite : public Drawable, public Transformable
        {
        protected:
            shared_ptr<Texture> texture;
            SDL_Rect clipping;
            ivec2 position;
        public:
            Sprite(const shared_ptr<Texture> &texture, const SDL_Rect &clipping, const ivec2 &position)
                : texture(texture), clipping(clipping), position(position)
            { }
        };
    }
}
