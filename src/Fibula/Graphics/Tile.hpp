#ifndef FIBULA_TILE_HPP
#define FIBULA_TILE_HPP

#include <glm/vec2.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class Tile
        {
        protected:
            const ivec2 size;
            const ivec2 position;
        public:
            Tile(const ivec2 &size, const ivec2 &position) : size(size), position(position)
            { }

            inline const ivec2 &getSize()
            {
                return size;
            }

            inline const ivec2 &getPosition()
            {
                return position;
            }
        };
    }
}


#endif //FIBULA_TILE_HPP
