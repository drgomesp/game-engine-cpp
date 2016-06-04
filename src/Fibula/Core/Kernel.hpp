#ifndef FIBULA_KERNEL_HPP
#define FIBULA_KERNEL_HPP

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }

    namespace Graphics {
        class Window;
    }
}

#include <memory>
#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Core {

        using namespace std;
        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using Listener = Fibula::EventDispatcher::Listener;
        using Window = Fibula::Graphics::Window;

        class Kernel
        {
        public:
            bool running = false;
        protected:
            bool booted = false;

            shared_ptr<Window> window;
            shared_ptr<Dispatcher> dispatcher;
        public:
            void addListener(const std::string &eventName, shared_ptr<Listener> listener);

            virtual void registerListeners() = 0;

            virtual void bootstrap();

            void run();

            virtual void terminate();
        };
    }
}

#endif //FIBULA_KERNEL_HPP
