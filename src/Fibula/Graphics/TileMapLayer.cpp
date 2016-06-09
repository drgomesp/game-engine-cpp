#include <Fibula/Graphics/TileMapLayer.hpp>

#include <SDL2/SDL_opengl.h>
#include <iostream>

using namespace std;
using namespace Fibula::Graphics;

void TileMapLayer::draw(SDL_Renderer* renderer)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        tile->draw(renderer);
    }
}

TILE_MAP_LAYER_LOAD TileMapLayer::load(vector<int> data)
{
    vector<int>::iterator it = data.begin();

    for (int c = 0; c < this->size.x; ++c) {
        for (int r = 0; r < this->size.y; ++r, ++it) {
            // Note(Daniel): Tiled Map Editor detail (start from 1 instead of 0)
            ivec2 coordinates = this->tileSet->getCoordinatesFromTileId(*it - 1);

            SDL_Rect clipping = {
                coordinates.x,
                coordinates.y,
                this->tileSet->getTileSize().x,
                this->tileSet->getTileSize().y,
            };

            shared_ptr<Tile> tile = make_shared<Tile>(
                *it,
                this->getTileSet()->getTileSize(),
                this->getTileSet()->getTexture(),
                clipping,
                ivec2(r, c)
            );

            this->tiles.push_back(tile);
        }
    }

    return TILE_MAP_LAYER_LOAD::SUCCESS;
}

void TileMapLayer::cleanUp(SDL_Renderer* renderer)
{
    SDL_DestroyTexture(this->getTileSet()->getTexture()->getSDLTexture());
}
