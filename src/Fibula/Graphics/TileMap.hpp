#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <memory>
#include <vector>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/TileMapLayer.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;
        using namespace std;

        class TileMap : public Drawable
        {
        protected:
            const string &name;
            const ivec2 size;
            vector<shared_ptr<TileMapLayer>> layers;
        public:
            TileMap(const string &name, const ivec2 &size) : name(name), size(size)
            { }

            void addLayer(shared_ptr<TileMapLayer> layer);
            void draw() override;
            void cleanUp() override;
        };
    }
}

#endif //FIBULA_TILEMAP_HPP
