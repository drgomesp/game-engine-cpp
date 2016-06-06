#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Texture
        {
        protected:
            const string filePath;
            SDL_Texture *texture;
        public:
            Texture(SDL_Renderer *renderer, const string &filePath);

            inline SDL_Texture *getSDLTexture()
            {
                return this->texture;
            }

            virtual ~Texture();
        };
    }
}
