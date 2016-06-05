#include "TileMapLayer.hpp"

#include <iostream>

using namespace Fibula::Graphics;

void TileMapLayer::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, this->tileSet->getTexture()->getSDLTexture(), NULL, NULL);
//    SDL_RenderCopy(renderer, this->tileSet.getTexture().getSDLTexture(), NULL, NULL);

//    for (auto it = this->tiles.begin(); it != this->tiles.end(); ++it) {
//        SDL_Rect clip = { 0, 0, 512, 512 };
//        SDL_Rect render = { 32, 32, 512, 512 };
//
//
//    }
}

TILE_MAP_LAYER_LOAD TileMapLayer::load(vector<int> data)
{
    int tWidth = this->getTileSet()->getTileSize().x;
    int tHeight = this->getTileSet()->getTileSize().y;

    for (int c = 0; c < this->size.x; ++c) {
        for (int r = 0; r < this->size.y; ++r) {
            Tile tile(ivec2(tWidth, tHeight), ivec2(c, r));
            this->tiles.push_back(&tile);
        }
    }

    return TILE_MAP_LAYER_LOAD::SUCCESS;
}

void TileMapLayer::cleanUp(SDL_Renderer* renderer)
{
//    SDL_DestroyTexture(this->getTileSet()->getTexture()->getSDLTexture());
}
