#include "Texture.hpp"

#include <SDL2/SDL_image.h>

using namespace Fibula::Graphics;

Texture::Texture(SDL_Renderer *renderer, const string &filePath)
    : filePath(filePath)
{
    SDL_Texture *texture;

    SDL_Surface *surface;
    surface = IMG_Load(filePath.c_str());

    if (surface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == NULL) {
        printf("Unable to create texture %s! SDL_image Error: %s\n", filePath.c_str(),
               IMG_GetError());
    }

    SDL_FreeSurface(surface);

    this->texture = texture;
}
