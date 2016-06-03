#include "TileMapLayer.hpp"

#include <memory>

using namespace std;
using namespace Fibula::Graphics::TileMap;

void TileMapLayer::createTilesFromVector(const vector<int> &data)
{
    for (auto it = data.begin(); it != data.end(); ++it) {
        shared_ptr<Tile> tile = make_shared<Tile>(this->tileSet->getTileWidth(), this->tileSet->getTileHeight(), *it);
        this->tiles.push_back(tile);
    }
}
