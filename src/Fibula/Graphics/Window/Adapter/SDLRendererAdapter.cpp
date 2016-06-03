#include "SDLRendererAdapter.hpp"

#include <vector>
#include <SDL2/SDL_image.h>
#include <Fibula/Graphics/TileMap/TileMap.hpp>
#include <Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;
using namespace Fibula::Graphics::Window;
using namespace Fibula::Graphics::Window::Adapter;

SDLRendererAdapter::SDLRendererAdapter(WindowAdapterInterface *window)
    : window(window)
{
    SDLWindowAdapter *sdlAdapter = dynamic_cast<SDLWindowAdapter *>(window);

    if (NULL == sdlAdapter) {
        throw runtime_error("Failed to retrieve window implementation from adapter");
    }

    this->renderer = SDL_CreateRenderer(sdlAdapter->getWindowImpl(), -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    if (!IMG_Init(IMG_INIT_PNG)) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    }

    std::string texturePath = "../../resources/mountain_landscape.png";
    SDL_Texture *texture;
    SDL_Surface *loadedSurface = IMG_Load(texturePath.c_str());

    if (loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError() );
    }

    texture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);

    if( texture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError() );
    }

    TileSet tileSet(512, 512, 32, 32, texture);
    TileMapLayer bush("Bush", true, &tileSet);

    vector<int> bushData = {
        375, 376,
        391, 392
    };

    bush.createTilesFromVector(bushData);


    SDL_FreeSurface(loadedSurface);

    //Clear screen
    SDL_RenderClear(this->renderer);

    int tileSetCols = tileSet.getWidth() / tileSet.getTileWidth();
    int tileSetRows = tileSet.getHeight() / tileSet.getTileHeight();

    for (int i = 0; i < bushData.size(); ++i) {
        SDL_Rect clip = { 32, 480, 32, 32 };
        SDL_Rect render = { i * 32, i * 32 / 2, 32, 32 };

        SDL_RenderCopy(this->renderer, texture, &clip, &render);
    }

    //Update screen
    SDL_RenderPresent(this->renderer);
}

SDLRendererAdapter::~SDLRendererAdapter()
{
    SDL_DestroyRenderer(this->renderer);
}
