#ifndef FIBULA_TILESET_HPP
#define FIBULA_TILESET_HPP

#include <SDL2/SDL.h>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/TileSetTexture.hpp>

namespace Fibula {
    namespace Graphics {
        class TileSetTexture;
    }
}

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class TileSet
        {
        protected:
            TileSetTexture &texture;
            const ivec2 size;
            const ivec2 tileSize;
        public:
            TileSet(TileSetTexture &texture, const ivec2 &size, const ivec2 &tileSize)
                : texture(texture), size(size), tileSize(tileSize)
            { }

            TileSetTexture &getTexture() const
            {
                return texture;
            }

            const ivec2 &getSize() const
            {
                return size;
            }

            const ivec2 &getTileSize() const
            {
                return tileSize;
            }
        };
    }
}


#endif //FIBULA_TILESET_HPP
