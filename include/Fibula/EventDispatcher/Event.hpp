#pragma once

#include <string>
#include <Fibula/EventDispatcher/Payload.hpp>

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
