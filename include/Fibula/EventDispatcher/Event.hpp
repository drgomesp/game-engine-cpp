#ifndef FIBULA_EVENT_HPP
#define FIBULA_EVENT_HPP

#include <string>
#include "Payload.hpp"

namespace Fibula {
    namespace EventDispatcher {
        class Event
        {
        protected:
            const Payload &payload;
        public:
            Event(const Payload &payload) : payload(payload)
            { }

            virtual const Payload &getPayload() const
            {
                return payload;
            }

            virtual ~Event()
            { }
        };
    }
}

#endif //FIBULA_EVENT_HPP
