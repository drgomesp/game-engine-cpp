#ifndef FIBULA_TILESET_HPP
#define FIBULA_TILESET_HPP

#include <SDL2/SDL.h>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class TileSet
            {
            protected:
                const int width;
                const int height;
                const int tileWidth;
                const int tileHeight;
                const SDL_Texture *texture;

            public:
                TileSet(const int width, const int height,
                        const int tileWidth, const int tileHeight,
                        const SDL_Texture *texture)
                    : width(width), height(height),
                      tileWidth(tileWidth),
                      tileHeight(tileHeight),
                      texture(texture)
                { }

                const int getWidth() const
                {
                    return width;
                }

                const int getHeight() const
                {
                    return height;
                }

                const int getTileWidth() const
                {
                    return tileWidth;
                }

                const int getTileHeight() const
                {
                    return tileHeight;
                }

                const SDL_Texture *getTexture() const
                {
                    return texture;
                }

                virtual ~TileSet()
                { }
            };
        }
    }
}

#endif //FIBULA_TILESET_HPP
