#include "TileMap.hpp"

using namespace Fibula::Graphics;

void TileMap::addLayer(TileMapLayer *layer)
{
    if (layer->getTiles().empty()) {
        throw runtime_error("Layer does not contain tiles and can't be added to tile map");
    }

    this->layers.push_back(layer);
}

void TileMap::draw(SDL_Renderer* renderer)
{
    for (ptr_vector<TileMapLayer>::iterator it = this->layers.begin(); it != this->layers.end(); ++it) {
        it->draw(renderer);
    }
}

void TileMap::cleanUp(SDL_Renderer* renderer)
{
    for (ptr_vector<TileMapLayer>::iterator it = this->layers.begin(); it != this->layers.end(); ++it) {
        it->cleanUp(renderer);
    }
}
