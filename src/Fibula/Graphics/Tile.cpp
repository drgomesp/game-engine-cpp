#include <Fibula/Graphics/Tile.hpp>

using namespace Fibula::Graphics;

void Tile::draw(SDL_Renderer *renderer)
{
    SDL_Rect render = {
        this->position.x * this->size.y,
        this->position.y * this->size.x,
        this->clipping.w,
        this->clipping.h
    };

    SDL_RenderCopy(
        renderer,
        this->texture->getSDLTexture(),
        &this->clipping,
        &render
    );
}

void Tile::cleanUp(SDL_Renderer *renderer)
{

}


