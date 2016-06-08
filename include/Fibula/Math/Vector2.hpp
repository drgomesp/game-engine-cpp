#pragma once

#include <tkDecls.h>

namespace Fibula {
    namespace Math {
        class Vector2
        {
        protected:
            float x, y;
        public:
            Vector2(float x, float y) : x(0.0), y(0.0)
            { }

            virtual ~Vector2()
            { }
        };
    }
}