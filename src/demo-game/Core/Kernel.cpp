#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

#include <Fibula/Graphics/TileSet.hpp>
#include <Fibula/Graphics/TileMap.hpp>
#include <Fibula/Graphics/TileMapLayer.hpp>
#include <Fibula/Graphics/Texture.hpp>

using namespace glm;
using namespace std;
using namespace Fibula::Graphics;
using namespace Game::Core;
using namespace Game::Listeners::SDL;

using EngineKernel = Fibula::Core::Kernel;

void Game::Core::Kernel::registerListeners()
{
    shared_ptr<MousePositionListener> mousePositionListener = make_shared<MousePositionListener>(this);
    this->dispatcher->addListener("event.sdl", mousePositionListener);
}

void Game::Core::Kernel::bootstrap()
{
    // Initialize the engine kernel
    EngineKernel::bootstrap();

    shared_ptr<Texture> groundTexture = make_shared<Texture>(this->window->getRenderer(), "resources/mountain_landscape.png");

    // Build the game stuff
    shared_ptr<TileSet> tileSet = make_shared<TileSet>(groundTexture, ivec2(16, 16), ivec2(32, 32), ivec2(512, 512));
    shared_ptr<TileMap> tileMap = make_shared<TileMap>("Demo TileMap", ivec2(6, 6));
    shared_ptr<TileMapLayer> ground = make_shared<TileMapLayer>("Ground", vec2(6, 6), true, 1.0f, tileSet);
    shared_ptr<TileMapLayer> mountains = make_shared<TileMapLayer>("Mountains", vec2(6, 6), true, 1.0f, tileSet);

    vector<int> groundData = {79, 79, 79, 79, 79, 80, 95, 95, 95, 79, 79, 80, 79, 79, 79, 80, 80, 80, 95, 95, 95, 96, 96, 80, 95, 96, 80, 80, 80, 80, 96, 96, 96, 96, 96, 80};
    vector<int> mountainsData = {0, 0, 0, 0, 0, 0, 0, 204, 0, 239, 240, 0, 0, 220, 0, 255, 256, 0, 0, 0, 238, 0, 204, 0, 0, 0, 254, 0, 220, 0, 0, 0, 0, 0, 0, 0};

    ground->load(groundData);
    mountains->load(mountainsData);

    tileMap->addLayer(ground);
    tileMap->addLayer(mountains);

    this->window->addDrawable(tileMap);
}
