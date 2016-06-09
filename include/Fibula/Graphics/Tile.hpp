#pragma once

#include <glm/vec2.hpp>
#include <Fibula/Graphics/Sprite.hpp>

namespace Fibula {
    namespace Graphics {

        class Tile : public Sprite
        {
        protected:
            const int id;
            const ivec2 &size;
        public:
            Tile(
                const int id,
                const ivec2 &size,
                const shared_ptr<Texture> &texture,
                const SDL_Rect &clipping,
                const ivec2 &position
            ) : id(id), size(size), Sprite(texture, clipping,position)
            { }

            void draw(SDL_Renderer *renderer) override;
            void cleanUp(SDL_Renderer *renderer) override;
        };
    }
}
