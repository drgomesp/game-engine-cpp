#include <Fibula/Graphics/TileMapLayer.hpp>

#include <SDL2/SDL_opengl.h>
#include <iostream>

using namespace std;
using namespace Fibula::Graphics;

void TileMapLayer::draw(SDL_Renderer* renderer)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        int position = tile->getId();

        int tileWidth = tile->getSize().x;
        int tileHeight = tile->getSize().y;
        int tilePositionX = tile->getPosition().y;
        int tilePositionY = tile->getPosition().x;

        ivec2 coordinates = this->tileSet->getTileCoordinates(position);

        SDL_Rect clipRect = { coordinates.x, coordinates.y, tileWidth, tileHeight };
        SDL_Rect renderRect = { tilePositionX * tileHeight, tilePositionY * tileWidth, clipRect.w, clipRect.h };

        SDL_RenderCopy(renderer, this->tileSet->getTexture()->getSDLTexture(), &clipRect, &renderRect);
    }
}

TILE_MAP_LAYER_LOAD TileMapLayer::load(vector<int> data)
{
    int tWidth = this->getTileSet()->getTileSize().x;
    int tHeight = this->getTileSet()->getTileSize().y;

    vector<int>::iterator it = data.begin();

    for (size_t c = 0; c < this->size.x; ++c) {
        for (size_t r = 0; r < this->size.y; ++r, ++it) {
            shared_ptr<Tile> tile = make_shared<Tile>(*it, ivec2(tWidth, tHeight), ivec2(c, r));
            this->tiles.push_back(tile);
        }
    }

    return TILE_MAP_LAYER_LOAD::SUCCESS;
}

void TileMapLayer::cleanUp(SDL_Renderer* renderer)
{
//    SDL_DestroyTexture(this->getTileSet()->getTexture()->getSDLTexture());
}
