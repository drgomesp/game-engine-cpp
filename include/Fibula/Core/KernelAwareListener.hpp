#pragma once

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Listener.hpp>

namespace Fibula {
    namespace Core {

        using Listener = Fibula::EventDispatcher::Listener;

        class KernelAwareListener : public Listener
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
