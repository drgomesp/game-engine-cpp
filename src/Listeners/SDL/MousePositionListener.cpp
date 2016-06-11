#include "MousePositionListener.hpp"

using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics;
using namespace Game::Listeners::SDL;

LISTENER_RESPONSE MousePositionListener::handleEvent(
    std::shared_ptr<const Fibula::EventDispatcher::Event> event) const
{
    const Fibula::Bridge::SDLEvent *sdlEvent = dynamic_cast<const Fibula::Bridge::SDLEvent *>(event.get());
    const Fibula::Bridge::SDLPayload sdlPayload = sdlEvent->getPayload();

    if (TileMap *tileMap = dynamic_cast<TileMap *>(sdlPayload.getCargo())) {
        switch (sdlPayload.getOriginalEvent().type) {
            default:
            case SDL_MOUSEMOTION:
                SDL_MouseMotionEvent m = sdlPayload.getOriginalEvent().motion;

                // Track mouse position

                return LISTENER_RESPONSE::SUCCESS;
        }
    }

    return LISTENER_RESPONSE::FAILURE;
}
