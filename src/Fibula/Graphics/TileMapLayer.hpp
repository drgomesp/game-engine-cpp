#pragma once

#include <vector>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/Tile.hpp>
#include <Fibula/Graphics/TileSet.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;
        using namespace std;

        class TileMapLayer
        {
        protected:
            const string &name;
            ivec2 size;
            bool visible = true;
            float opacity = 1.0f;
            vector<unique_ptr<Tile>> tiles;
            TileSet tileSet;
        public:
            TileMapLayer(
                const string &name,
                const ivec2 &size,
                bool visible,
                float opacity,
                const TileSet &tileSet)
                : name(name), size(size), visible(visible), opacity(opacity), tileSet(tileSet)
            { }
        };
    }
}
