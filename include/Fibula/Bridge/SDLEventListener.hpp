#ifndef FIBULA_SDLEVENTLISTENER_HPP
#define FIBULA_SDLEVENTLISTENER_HPP

#include "../Core/KernelAwareListener.hpp"

namespace Fibula {
    namespace Bridge {

        using namespace std;
        using Event = Fibula::EventDispatcher::Event;
        using Kernel = Fibula::Core::Kernel;
        using KernelAwareListener = Fibula::Core::KernelAwareListener;

        class SDLEventListener : public KernelAwareListener
        {
        public:
            virtual LISTENER_RESPONSE handleEvent(shared_ptr<const Event> event) const override;

            SDLEventListener(Kernel *kernel) : KernelAwareListener(kernel)
            { }
        };
    }
}

#endif //FIBULA_SDLEVENTLISTENER_HPP
