#pragma once

#include <memory>
#include <vector>
#include <glm/vec2.hpp>

#include <Fibula/EventDispatcher/Cargo.hpp>
#include <Fibula/Graphics/TileMapLayer.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;
        using ivec2 = glm::ivec2;
        using Cargo = Fibula::EventDispatcher::Cargo;

        class TileMap : public Drawable, public Cargo
        {
        protected:
            const string &name;
            const ivec2 size;
            vector<shared_ptr<TileMapLayer>> layers;
        public:
            TileMap(const string &name, const ivec2 &size) : name(name), size(size)
            { }

            void addLayer(shared_ptr<TileMapLayer> layer);
            void draw(SDL_Renderer* renderer) override;
            void cleanUp(SDL_Renderer* renderer) override;

            vector<shared_ptr<TileMapLayer>> &getLayers()
            {
                return layers;
            }

            virtual ~TileMap()
            { }
        };
    }
}
