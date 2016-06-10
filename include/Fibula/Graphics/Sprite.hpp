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
            SDL_Rect rectangle;
            ivec2 size;
            ivec2 position;
        public:
            Sprite(
                const shared_ptr<Texture> &texture,
                const SDL_Rect &rectangle,
                const ivec2 &size,
                const ivec2 &position
            ) : texture(texture), rectangle(rectangle), size(size), position(position)
            { }

            virtual void draw(SDL_Renderer *renderer) override;
            virtual void cleanUp(SDL_Renderer *renderer) override;
        };
    }
}
