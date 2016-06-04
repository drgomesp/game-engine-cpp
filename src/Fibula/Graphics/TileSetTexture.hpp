#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class TileSetTexture : public Drawable
        {
        protected:
            const string filePath;
            SDL_Texture *texture;
            SDL_Surface *surface;
        public:
            TileSetTexture(const string filePath);

            SDL_Surface *getSurface() const
            {
                return surface;
            }

            SDL_Texture *getTexture() const
            {
                return texture;
            }

            virtual void draw(SDL_Renderer *renderer) override;
            virtual void cleanUp(SDL_Renderer *renderer) override;
        };
    }
}
