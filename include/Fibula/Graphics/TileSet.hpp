#pragma once

#include <SDL2/SDL.h>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/Texture.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;

        class TileSet
        {
        protected:
            shared_ptr<Texture> texture;
            const ivec2 size;
            const ivec2 tileSize;
            const ivec2 pixelSize;
        public:
            TileSet(
                shared_ptr<Texture> texture,
                const ivec2 &size,
                const ivec2 &tileSize,
                const ivec2 &pixelSize
            ) : texture(texture), size(size), tileSize(tileSize), pixelSize(pixelSize)
            { }

            ivec2 getCoordinatesFromId(int id);

            const shared_ptr<Texture> &getTexture() const
            {
                return texture;
            }

            const ivec2 &getSize() const
            {
                return this->size;
            }

            const ivec2 &getTileSize() const
            {
                return this->tileSize;
            }

            const ivec2 &getPixelSize() const
            {
                return pixelSize;
            }
        };
    }
}
