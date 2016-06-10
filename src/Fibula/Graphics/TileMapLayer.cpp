#include <Fibula/Graphics/TileMapLayer.hpp>

using namespace std;
using namespace Fibula::Graphics;

void TileMapLayer::draw(SDL_Renderer* renderer)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        tile->draw(renderer);
    }
}

bool TileMapLayer::load(vector<int> data)
{
    vector<int>::iterator it = data.begin();

    for (int c = 0; c < this->size.x; ++c) {
        for (int r = 0; r < this->size.y; ++r, ++it) {
            // NOTE: Tiled Map Editor detail (start from 1 instead of 0)
            ivec2 coordinates = this->tileSet->getCoordinatesFromId(*it - 1);

            SDL_Rect clipping = {
                coordinates.x,
                coordinates.y,
                this->tileSet->getTileSize().x,
                this->tileSet->getTileSize().y,
            };

            shared_ptr<Tile> tile = make_shared<Tile>(
                *it,
                this->getTileSet()->getTexture(),
                clipping,
                this->getTileSet()->getTileSize(),
                ivec2(r, c)
            );

            this->tiles.push_back(tile);
        }
    }

    return true;
}

void TileMapLayer::cleanUp(SDL_Renderer* renderer)
{
    SDL_DestroyTexture(this->getTileSet()->getTexture()->getSDLTexture());
}
