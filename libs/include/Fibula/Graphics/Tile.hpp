#pragma once

#include <glm/vec2.hpp>
#include "Sprite.hpp"

namespace Fibula {
    namespace Graphics {

        class Tile : public Sprite
        {
        protected:
            const int id;
        public:
            Tile(
                const int id,
                const shared_ptr<Texture> &texture,
                const SDL_Rect &rectangle,
                const ivec2 &size,
                const ivec2 &position
            ) : id(id), Sprite(texture, rectangle, size, position)
            { }
        };
    }
}
