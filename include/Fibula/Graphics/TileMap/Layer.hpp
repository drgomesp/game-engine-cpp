#ifndef FIBULA_TILEMAPLAYER_HPP
#define FIBULA_TILEMAPLAYER_HPP

#include <string>
#include <vector>

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Tile.hpp>
#include <Fibula/Graphics/TileMap/TileSet.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using namespace std;

            class Layer : public Drawable
            {
            protected:
                const string &name;
                unsigned int widthInTiles;
                unsigned int heightInTiles;
                bool visible = true;
                float opacity = 1.0f;
                vector<shared_ptr<Tile>> tiles;
                shared_ptr<TileSet> tileSet;
            public:
                Layer(
                    const string &name,
                    unsigned int widthInTiles,
                    unsigned int heightInTiles,
                    bool visible,
                    float opacity,
                    const shared_ptr<TileSet> &tileSet
                );

                virtual void draw(shared_ptr<Window> window) override;

                const shared_ptr<TileSet> &getTileSet() const;
                void addTile(shared_ptr<Tile> tile);
            };
        }
    }
}

#endif //PROJECT_TILEMAPLAYER_HPP
