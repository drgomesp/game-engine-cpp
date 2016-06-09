#pragma once

#include <glm/vec2.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class Transform
        {
        protected:
            ivec2 position;
            ivec2 rotation;
            ivec2 scale;
        public:
            Transform(const ivec2 &position, const ivec2 &rotation, const ivec2 &scale)
                : position(position), rotation(rotation), scale(scale)
            { }

            ~Transform()
            { }
        };
    }
}
