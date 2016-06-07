#pragma once

#include <vector>
#include <glm/vec2.hpp>
#include <SDL2/SDL.h>

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/Tile.hpp>
#include <Fibula/Graphics/TileSet.hpp>

enum class TILE_MAP_LAYER_LOAD
{
    SUCCESS = 0, FAILURE = -1
};

namespace Fibula {
    namespace Graphics {

        using namespace std;
        using namespace Fibula::Graphics;
        using namespace glm;

        class TileMapLayer : public Drawable
        {
        protected:
            const string &name;
            ivec2 size;
            bool visible = true;
            float opacity = 1.0f;
            vector<shared_ptr<Tile>> tiles;
            shared_ptr<TileSet> tileSet;
        public:
            TileMapLayer(
                const string &name,
                const ivec2 &size,
                bool visible,
                float opacity,
                shared_ptr<TileSet> tileSet
            ) : name(name), size(size), visible(visible), opacity(opacity), tileSet(tileSet)
            { }

            void draw(SDL_Renderer *renderer) override;
            void cleanUp(SDL_Renderer *renderer) override;
            TILE_MAP_LAYER_LOAD load(vector<int> data);

            shared_ptr<TileSet> getTileSet()
            {
                return this->tileSet;
            }

            const vector<shared_ptr<Tile>> &getTiles() const
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
