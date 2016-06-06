#ifndef FIBULA_SDLEVENT_H
#define FIBULA_SDLEVENT_H

#include "SDLPayload.hpp"
#include "../EventDispatcher/Event.hpp"

namespace Fibula {
    namespace Bridge {
        using Event = Fibula::EventDispatcher::Event;

        class SDLEvent : public Event
        {
        private:
            const SDLPayload &payload;
        public:
            SDLEvent(const SDLPayload &payload)
                : Event(payload), payload(payload)
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

#endif //FIBULA_SDLEVENT_H
