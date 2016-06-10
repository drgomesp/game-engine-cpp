#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

#include <Fibula/Graphics/TileSet.hpp>
#include <Fibula/Graphics/TileMap.hpp>

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

    shared_ptr<Texture> texture = make_shared<Texture>(this->window->getRenderer(), "resources/mountain_landscape_grid.png");

    // Build the game stuff
    shared_ptr<TileSet> tileSet = make_shared<TileSet>(texture, ivec2(16, 16), ivec2(32, 32), ivec2(512, 512));
    shared_ptr<TileMap> tileMap = make_shared<TileMap>("Demo TileMap", ivec2(15, 24));
    shared_ptr<TileMapLayer> ground = make_shared<TileMapLayer>("Ground", vec2(15, 24), true, 1.0f, tileSet);
    shared_ptr<TileMapLayer> mountains = make_shared<TileMapLayer>("Mountains", vec2(15, 24), true, 1.0f, tileSet);

    /* Comes from Tiled Map Editor */
    vector<int> groundData = {79, 80, 79, 80, 79, 80, 79, 172, 173, 173, 173, 173, 173, 173, 173, 174, 80, 96, 96, 80, 80, 80, 80, 80, 95, 96, 95, 96, 95, 96, 95, 172, 173, 173, 173, 173, 173, 173, 173, 174, 80, 95, 96, 96, 96, 96, 96, 96, 79, 80, 79, 80, 79, 80, 79, 188, 159, 173, 173, 173, 173, 173, 173, 174, 80, 80, 95, 95, 95, 96, 79, 80, 95, 96, 95, 96, 95, 96, 95, 96, 188, 159, 173, 173, 173, 173, 160, 190, 96, 96, 95, 96, 95, 96, 95, 96, 79, 80, 79, 80, 79, 80, 79, 80, 79, 172, 173, 173, 173, 173, 174, 96, 79, 80, 80, 80, 79, 80, 79, 80, 95, 96, 95, 96, 95, 96, 95, 96, 95, 172, 173, 173, 173, 173, 174, 80, 80, 96, 96, 96, 95, 96, 95, 96, 79, 80, 79, 80, 79, 80, 79, 80, 79, 172, 173, 173, 173, 173, 174, 96, 96, 80, 156, 157, 158, 80, 79, 80, 95, 96, 95, 96, 95, 96, 95, 96, 95, 188, 29, 29, 29, 29, 190, 96, 95, 96, 172, 173, 174, 96, 95, 96, 79, 80, 79, 80, 79, 80, 79, 80, 79, 111, 60, 61, 61, 62, 112, 80, 79, 80, 188, 189, 190, 80, 79, 80, 95, 96, 95, 96, 95, 96, 95, 96, 95, 127, 76, 77, 77, 78, 128, 96, 95, 96, 95, 96, 95, 96, 95, 96, 79, 80, 79, 156, 157, 158, 79, 80, 79, 111, 76, 77, 77, 78, 112, 80, 79, 80, 79, 80, 79, 80, 79, 80, 95, 96, 95, 172, 173, 174, 95, 96, 95, 127, 76, 77, 77, 78, 128, 96, 95, 96, 95, 96, 95, 96, 95, 96, 79, 80, 79, 188, 189, 190, 79, 80, 79, 111, 76, 77, 77, 78, 112, 80, 79, 80, 79, 80, 79, 80, 79, 80, 95, 96, 95, 96, 95, 96, 95, 96, 95, 127, 76, 77, 77, 78, 128, 96, 95, 96, 95, 96, 95, 96, 95, 96, 79, 80, 79, 80, 79, 80, 79, 80, 79, 111, 76, 77, 77, 78, 112, 80, 79, 80, 79, 80, 79, 80, 79, 80};
//    vector<int> mountainsData = {0, 0, 0, 0, 0, 0, 0, 0, 17, 18, 24, 24, 24, 24, 25, 26, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 66, 39, 40, 40, 41, 42, 42, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 66, 55, 40, 36, 52, 58, 58, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 66, 40, 51, 52, 51, 52, 58, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 50, 40, 52, 51, 51, 52, 53, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 66, 40, 68, 67, 67, 68, 69, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81, 82, 83, 191, 192, 84, 84, 85, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 98, 99, 207, 208, 100, 100, 101, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> mountainsData = {0, 0, 0, 0, 0, 0, 0, 0, 17, 18, 24, 24, 24, 24, 25, 26, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 33, 66, 39, 40, 40, 41, 42, 42, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 66, 55, 40, 36, 52, 58, 58, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 66, 40, 51, 52, 51, 52, 58, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49, 50, 40, 52, 51, 51, 52, 53, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 66, 40, 68, 67, 67, 68, 69, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81, 82, 83, 191, 192, 84, 84, 85, 70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 98, 99, 207, 208, 100, 100, 101, 86};

    tileMap->addLayer(ground, groundData);
    tileMap->addLayer(mountains, mountainsData);

    this->window->addDrawable(tileMap);

//    SDL_Rect clipping = {128, 128, 64, 64};
//    auto sprite = make_shared<Sprite>(texture, clipping, ivec2(64, 64), ivec2(0, 0));
//    this->window->addDrawable(sprite);
}
