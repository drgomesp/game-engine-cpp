#ifndef FIBULA_KERNELAWARELISTENER_HPP
#define FIBULA_KERNELAWARELISTENER_HPP

#include <memory>

#include "Kernel.hpp"
#include "../EventDispatcher/Listener.hpp"
#include "../Bridge/SDLEvent.hpp"

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

#endif //FIBULA_KERNELAWARELISTENER_H
