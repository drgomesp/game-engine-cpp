#include "../../../include/Fibula/Graphics/TileMap.hpp"

using namespace Fibula::Graphics;

void TileMap::addLayer(shared_ptr<TileMapLayer> layer)
{
    if (layer->getTiles().empty()) {
        throw runtime_error("Layer does not contain tiles and can't be added to tile map");
    }

    this->layers.push_back(layer);
}

void TileMap::draw(SDL_Renderer* renderer)
{
    for (shared_ptr<TileMapLayer> layer : this->layers) {
        layer->draw(renderer);
    }
}

void TileMap::cleanUp(SDL_Renderer* renderer)
{
    for (shared_ptr<TileMapLayer> layer : this->layers) {
        layer->cleanUp(renderer);
    }
}
