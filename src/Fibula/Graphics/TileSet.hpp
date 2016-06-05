#ifndef FIBULA_TILESET_HPP
#define FIBULA_TILESET_HPP

#include <SDL2/SDL.h>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/Texture.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class TileSet
        {
        protected:
            Texture *texture;
            const ivec2 size;
            const ivec2 tileSize;
        public:
            TileSet(Texture *texture, const ivec2 &size, const ivec2 &tileSize)
                : texture(texture), size(size), tileSize(tileSize)
            { }

            Texture *getTexture() const
            {
                return this->texture;
            }

            const ivec2 &getSize() const
            {
                return this->size;
            }

            const ivec2 &getTileSize() const
            {
                return this->tileSize;
            }
        };
    }
}


#endif //FIBULA_TILESET_HPP
