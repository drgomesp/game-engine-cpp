#include "TileSetTexture.hpp"

#include <SDL2/SDL_image.h>

using namespace Fibula::Graphics;

TileSetTexture::TileSetTexture(const string &filePath) : filePath(filePath)
{
    this->surface = IMG_Load(filePath.c_str());

    if (this->surface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError() );
    }

    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
}
