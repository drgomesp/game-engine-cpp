#pragma once

#include <Fibula/Core/Kernel.h>
#include <Fibula/EventDispatcher/Listener.h>

namespace Fibula {
    namespace EventDispatcher {
        using namespace Core;

        class KernelAwareListener : public Listener {
            std::shared_ptr<Kernel> kernel;
        public:
            KernelAwareListener(std::shared_ptr<Kernel> kernel) : kernel(kernel) { }
        };
    }
}

