#include "MousePositionListener.hpp"

using namespace Game::Listeners::SDL;

LISTENER_RESPONSE MousePositionListener::handleEvent(
    std::shared_ptr<const Fibula::EventDispatcher::Event> event) const
{
    const Fibula::Bridge::SDLEvent *sdlEvent = dynamic_cast<const Fibula::Bridge::SDLEvent *>(event.get());
    const Fibula::Bridge::SDLPayload sdlPayload = sdlEvent->getPayload();

    switch (sdlPayload.getOriginalEvent().type) {
        default:
        case SDL_MOUSEMOTION:
            SDL_MouseMotionEvent m = sdlPayload.getOriginalEvent().motion;
            std::cout << "[MousePositionListener::handleEvent] -> Mouse position is [x:" << m.x << "][y:" << m.y << "]" << std::endl;
            return LISTENER_RESPONSE::SUCCESS;
    }
}
