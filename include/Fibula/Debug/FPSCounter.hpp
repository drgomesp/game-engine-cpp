#pragma once

namespace Fibula {
    namespace Debug {
        class FPSCounter
        {
        public:
            static void calculate(float &fps, float &frameTime);
        };
    }
}