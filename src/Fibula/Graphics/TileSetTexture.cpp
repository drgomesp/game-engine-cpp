#include "TileSetTexture.hpp"

#include <SDL2/SDL_image.h>

using namespace Fibula::Graphics;

TileSetTexture::TileSetTexture(SDL_Renderer *renderer, const string filePath) : filePath(filePath)
{
    this->surface = IMG_Load(filePath.c_str());

    if (this->surface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError() );
    }

    this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);

    if (this->texture == NULL) {
        printf( "Unable to create texture %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
    }

    SDL_FreeSurface(this->surface);
}

void TileSetTexture::draw()
{

}

void TileSetTexture::cleanUp()
{

}
