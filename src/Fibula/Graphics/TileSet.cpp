#include <Fibula/Graphics/TileSet.hpp>

using namespace glm;
using namespace Fibula::Graphics;

ivec2 TileSet::getTileCoordinates(int position)
{
    ivec2 coordinates(0, 0);
    int tilesPerColumn = this->pixelSize.x / this->tileSize.x;

    int row = (int) floor(position / tilesPerColumn);
    int col = (int) floor(position % tilesPerColumn);

    coordinates.x = col * this->tileSize.x;
    coordinates.y = row * this->tileSize.y;

    return coordinates;
}
