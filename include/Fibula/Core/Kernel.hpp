#pragma once

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
            float fps;
            float frameTime;
        protected:
            bool booted = false;

            shared_ptr<Window> window;
            shared_ptr<Dispatcher> dispatcher;
        public:
            void run();
            virtual void bootstrap();
            virtual void terminate();

            /* Game specific functions */
            virtual void registerListeners();
            virtual void handleEvents();
            virtual void handleInputs();
            virtual void update();
        };
    }
}
