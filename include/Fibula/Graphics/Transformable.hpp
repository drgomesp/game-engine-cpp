#pragma once

#include <Fibula/Graphics/Transform.hpp>

namespace Fibula {
    namespace Graphics {
        class Transformable
        {
        protected:
            mutable Transform;
        public:
            Transformable()
            { }

            ~Transformable()
            { }
        };
    }
}