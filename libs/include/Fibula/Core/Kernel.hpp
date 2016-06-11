#pragma once


#include <memory>
#include "EventDispatcher/Dispatcher.hpp"
#include "EventDispatcher/EventHandler.hpp"
#include "Graphics/Window.hpp"

namespace Fibula {
    namespace EventDispatcher {
        class Dispatcher;
    }

    namespace Graphics {
        class Window;
    }
}

namespace Fibula {
    namespace Core {

        using namespace std;

        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using EventHandler = Fibula::EventDispatcher::EventHandler;
        using Listener = Fibula::EventDispatcher::Listener;
        using Window = Fibula::Graphics::Window;

        class Kernel : public EventHandler
        {
        public:
            bool running = false;
        protected:
            float fps;
            float frameTime;
            bool booted = false;
            shared_ptr<Window> window;
            shared_ptr<Dispatcher> dispatcher;
        public:
            void run();
            void terminate();

            /* Game specific functions */
            virtual void bootstrap();
            virtual void registerListeners();
            virtual void handleEvents() override;
            virtual void handleInputs();
            virtual void update();
        };
    }
}
