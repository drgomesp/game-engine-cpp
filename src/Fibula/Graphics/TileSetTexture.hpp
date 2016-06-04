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
            const string &filePath;
            SDL_Texture *texture;
            SDL_Surface *surface;
        public:
            TileSetTexture(const string &filePath);

        private:
            void draw() override
            { }

            void cleanUp() override
            { }
        };
    }
}
