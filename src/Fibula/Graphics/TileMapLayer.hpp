#pragma once

#include <vector>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/Tile.hpp>
#include <Fibula/Graphics/TileSet.hpp>
#include <Fibula/Graphics/Drawable.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

enum class TILE_MAP_LAYER_LOAD
{
    SUCCESS = 0, FAILURE = -1
};

namespace Fibula {
    namespace Graphics {

        using namespace glm;
        using namespace boost;

        class TileMapLayer : public Drawable
        {
        protected:
            const string &name;
            ivec2 size;
            bool visible = true;
            float opacity = 1.0f;
            ptr_vector<Tile> tiles;
            TileSet *tileSet;
        public:
            TileMapLayer(
                const string &name,
                const ivec2 &size,
                bool visible,
                float opacity,
                TileSet *tileSet)
                : name(name), size(size), visible(visible), opacity(opacity), tileSet(tileSet)
            { }

            void draw(SDL_Renderer* renderer) override;
            void cleanUp(SDL_Renderer* renderer) override;
            TILE_MAP_LAYER_LOAD load(vector<int> data);

            TileSet *getTileSet()
            {
                return this->tileSet;
            }

            const ptr_vector<Tile> &getTiles() const
            {
                return this->tiles;
            }

            float getOpacity() const
            {
                return this->opacity;
            }

            bool isVisible() const
            {
                return visible;
            }
        };
    }
}
