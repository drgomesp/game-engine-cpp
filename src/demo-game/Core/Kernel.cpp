#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

using namespace std;
using namespace Game::Core;
using namespace Game::Listeners::SDL;

void Kernel::registerListeners()
{
    std::shared_ptr<MousePositionListener> mousePositionListener = make_shared<MousePositionListener>(this);
    this->dispatcher->addListener("event.sdl", mousePositionListener);
}
