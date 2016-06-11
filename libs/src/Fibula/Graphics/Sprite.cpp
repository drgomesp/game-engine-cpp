#include "Graphics/Sprite.hpp"

using namespace Fibula::Graphics;


void Sprite::draw(SDL_Renderer *renderer)
{
    SDL_Rect render = {
        this->position.x * this->size.x,
        this->position.y * this->size.y,
        this->size.x,
        this->size.y
    };

    SDL_RenderCopy(
        renderer,
        this->texture->getSDLTexture(),
        &this->rectangle,
        &render
    );
}

void Sprite::cleanUp(SDL_Renderer *renderer)
{

}
