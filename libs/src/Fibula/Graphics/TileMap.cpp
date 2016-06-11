#include "Graphics/TileMap.hpp"

using namespace Fibula::Graphics;

void TileMap::addLayer(shared_ptr<TileMapLayer> layer, vector<int> data)
{
    if (layer->load(data)) {
        this->layers.push_back(layer);
    }
}

void TileMap::draw(SDL_Renderer *renderer)
{
    for (shared_ptr<TileMapLayer> layer : this->layers) {
        layer->draw(renderer);
    }
}

void TileMap::cleanUp(SDL_Renderer *renderer)
{
    for (shared_ptr<TileMapLayer> layer : this->layers) {
        layer->cleanUp(renderer);
    }
}
