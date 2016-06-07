#pragma once

#include <memory>

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Listener.hpp>
#include <Fibula/Bridge/SDLEvent.hpp>

namespace Fibula {
    namespace Core {
        class KernelAwareListener : public Fibula::EventDispatcher::Listener
        {
        protected:
            Kernel *kernel;
        public:
            KernelAwareListener(Kernel *kernel) : kernel(kernel)
            { }

            virtual ~KernelAwareListener()
            { }
        };
    }
}
