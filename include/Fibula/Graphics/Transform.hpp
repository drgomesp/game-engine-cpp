#pragma once

#include <Fibula/Math/Vector2.hpp>

namespace Fibula {
    namespace Graphics {

        using Vector2 = Fibula::Math::Vector2;

        class Transform
        {
        protected:
            Vector2 position;
            Vector2 rotation;
            Vector2 scale;
        public:
            Transform(const Vector2 &position, const Vector2 &rotation, const Vector2 &scale)
                : position(position), rotation(rotation), scale(scale)
            { }

            ~Transform()
            { }
        };
    }
}
