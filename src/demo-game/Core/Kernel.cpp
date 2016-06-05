#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

#include <Fibula/Graphics/TileMap.hpp>

using namespace glm;
using namespace std;
using namespace Fibula::Graphics;
using namespace Game::Core;
using namespace Game::Listeners::SDL;

using EngineKernel = Fibula::Core::Kernel;

void Game::Core::Kernel::registerListeners()
{
    std::shared_ptr<MousePositionListener> mousePositionListener = make_shared<MousePositionListener>(this);
    this->dispatcher->addListener("event.sdl", mousePositionListener);
}

void Game::Core::Kernel::bootstrap()
{
    // Initialize the engine kernel
    EngineKernel::bootstrap();

    Texture groundTexture(this->window->getRenderer(), "../../resources/mountain_landscape.png");

    // Build the game stuff
    TileSet *tileSet = new TileSet(&groundTexture, ivec2(15, 15), ivec2(32, 32));
    TileMap *tileMap = new TileMap("Demo TileMap", ivec2(2, 2));
    TileMapLayer *ground = new TileMapLayer("Ground", vec2(2, 2), true, 1.0f, tileSet);
    vector<int> groundData = {116, 117, 132, 133};

    ground->load(groundData);
    tileMap->addLayer(ground);

    this->window->addDrawable(tileMap);
}
