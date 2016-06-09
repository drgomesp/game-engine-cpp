#include <Fibula/Graphics/TileSet.hpp>

using namespace glm;
using namespace Fibula::Graphics;

ivec2 TileSet::getCoordinatesFromId(int id)
{
    ivec2 coordinates(0, 0);
    int tilesPerColumn = this->pixelSize.x / this->tileSize.x;

    int row = (int) floor(id / tilesPerColumn);
    int col = (int) floor(id % tilesPerColumn);

    coordinates.x = col * this->tileSize.x;
    coordinates.y = row * this->tileSize.y;

    return coordinates;
}

int TileSet::getIdFromCoordinates(const ivec2 &coordinates)
{
    printf("[x:%i][y:%i]\n", coordinates.x, coordinates.y);
}
