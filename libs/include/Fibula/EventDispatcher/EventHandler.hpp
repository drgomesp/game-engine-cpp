#pragma once

namespace Fibula {
    namespace EventDispatcher {
        class EventHandler {
        public:
            virtual void handleEvents() = 0;
        };
    }
}