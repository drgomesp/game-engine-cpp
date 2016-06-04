#ifndef FIBULA_TEXTURE_HPP
#define FIBULA_TEXTURE_HPP

#include <string>
#include <SDL2/SDL.h>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Texture
        {
            friend class TileMapLayer;
        protected:
            const string filePath;
            SDL_Texture *texture;
        public:
            Texture(SDL_Renderer *renderer, const string &filePath);
        private:
            inline SDL_Texture *getSDLTexture()
            {
                return this->texture;
            }
        };
    }
}


#endif //FIBULA_TEXTURE_HPP
