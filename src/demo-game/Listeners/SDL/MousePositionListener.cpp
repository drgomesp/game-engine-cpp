#include "MousePositionListener.hpp"

#include <Fibula/Graphics/TileMap.hpp>

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

                for (shared_ptr<TileMapLayer> layer : tileMap->getLayers()) {
//                    printf("Tile [id: %i]\n",
//                           layer->getTileSet()->getIdFromCoordinates(ivec2(m.x, m.y)));
                }

                return LISTENER_RESPONSE::SUCCESS;
        }
    }

    return LISTENER_RESPONSE::FAILURE;
}
