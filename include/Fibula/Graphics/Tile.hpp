#pragma once

#include <glm/vec2.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class Tile
        {
        protected:
            const int id;
            const ivec2 position;
            const ivec2 size;
        public:
            Tile(const int id, const ivec2 &size, const ivec2 &position)
                : id(id), position(position), size(size)
            { }

            int getId()
            {
                return id;
            }

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
