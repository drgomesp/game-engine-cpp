#pragma once

#include <SDL_events.h>

#include <Fibula/EventDispatcher/Payload.hpp>

namespace Fibula {
    namespace Bridge {
        using Payload = Fibula::EventDispatcher::Payload;

        class SDLPayload : public Payload
        {
            const SDL_Event &originalEvent;
        public:
            SDLPayload(const SDL_Event &originalEvent) : originalEvent(originalEvent)
            { }

            const SDL_Event &getOriginalEvent() const
            {
                return originalEvent;
            }

            virtual ~SDLPayload()
            { }
        };
    }
}
