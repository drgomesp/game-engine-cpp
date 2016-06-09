#pragma once

#include <Fibula/Bridge/SDLPayload.hpp>
#include <Fibula/EventDispatcher/Event.hpp>

namespace Fibula {
    namespace Bridge {

        using Event = Fibula::EventDispatcher::Event;

        class SDLEvent : public Event
        {
        protected:
            const SDLPayload &payload;
        public:
            SDLEvent(const SDLPayload &payload)
                : Event(payload),
                  payload(payload)
            { }

            const SDLPayload &getPayload() const
            {
                return payload;
            }

            virtual ~SDLEvent()
            { }
        };
    }
}
