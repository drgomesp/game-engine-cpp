#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <memory>
#include <vector>
#include <glm/vec2.hpp>

#include <Fibula/Graphics/TileMapLayer.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace boost;
        using namespace glm;

        class TileMap : public Drawable
        {
        protected:
            const string &name;
            const ivec2 size;
            ptr_vector<TileMapLayer> layers;
        public:
            TileMap(const string &name, const ivec2 &size) : name(name), size(size)
            { }

            void addLayer(TileMapLayer *layer);
            void draw(SDL_Renderer* renderer) override;
            void cleanUp(SDL_Renderer* renderer) override;
        };
    }
}

#endif //FIBULA_TILEMAP_HPP
