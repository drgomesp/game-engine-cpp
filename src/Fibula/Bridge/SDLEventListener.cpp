#include <Fibula/Bridge/SDLEventListener.hpp>

#include <iostream>

using namespace std;
using namespace Fibula::Bridge;
using namespace Fibula::EventDispatcher;

LISTENER_RESPONSE SDLEventListener::handleEvent(shared_ptr<const Event> event) const
{
    const SDLEvent *sdlEvent = dynamic_cast<const SDLEvent *>(event.get());

    if (!sdlEvent) {
        return LISTENER_RESPONSE::FAILURE;
    }

    cout << "SDLEventListener::handleEvent()" << endl;

    const SDLPayload sdlPayload = sdlEvent->getPayload();

    switch (sdlPayload.getOriginalEvent().type) {
        case SDL_QUIT:
            this->kernel->terminate();
            return LISTENER_RESPONSE::SUCCESS;
        case SDL_KEYUP:
            if (sdlPayload.getOriginalEvent().key.keysym.sym == SDLK_ESCAPE) {
                this->kernel->terminate();
                return LISTENER_RESPONSE::SUCCESS;
            }
        default:
            return LISTENER_RESPONSE::FAILURE;
    }
}
