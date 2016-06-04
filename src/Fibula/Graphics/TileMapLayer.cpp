#include "TileMapLayer.hpp"

#include <iostream>

using namespace Fibula::Graphics;

void TileMapLayer::draw()
{
    for (auto it = this->tiles.begin(); it != this->tiles.end(); ++it) {
        SDL_Rect clip = { 0, 0, 512, 512 };
        SDL_Rect render = { 32, 32, 512, 512 };

        SDL_RenderCopy(this->renderer, this->tileSet.getTexture().getTexture(), NULL, NULL);
    }
}

TILE_MAP_LAYER_LOAD TileMapLayer::load(vector<int> data)
{
    int tWidth = this->getTileSet().getTileSize().x;
    int tHeight = this->getTileSet().getTileSize().y;

    for (int c = 0; c < this->size.x; ++c) {
        for (int r = 0; r < this->size.y; ++r) {
            this->tiles.push_back(make_shared<Tile>(ivec2(tWidth, tHeight), ivec2(c, r)));
        }
    }

    return TILE_MAP_LAYER_LOAD::SUCCESS;
}

void TileMapLayer::cleanUp()
{
    SDL_DestroyTexture(this->getTileSet().getTexture().getTexture());
    SDL_DestroyRenderer(this->renderer);
}
