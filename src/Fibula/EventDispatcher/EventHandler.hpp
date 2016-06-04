#ifndef FIBULA_EVENTAWARE_HPP
#define FIBULA_EVENTAWARE_HPP

namespace Fibula {
    namespace EventDispatcher {
        class EventHandler {
        public:
            virtual void handleEvents() = 0;
        };
    }
}

#endif //FIBULA_EVENTAWARE_HPP