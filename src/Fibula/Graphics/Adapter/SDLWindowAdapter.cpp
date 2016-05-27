#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>

using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Adapter;
using namespace Fibula::Bridge::EventDispatcher;

SDLWindowAdapter::SDLWindowAdapter(
        const std::string &title,
        const int width,
        const int height,
        Dispatcher &dispatcher)
            : WindowAdapterInterface(title, width, height, dispatcher)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL");
    }
}


void SDLWindowAdapter::create(
        const std::string &title,
        const int width,
        const int height,
        Dispatcher &dispatcher
) {
    this->window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_OPENGL
    );

    if (this->window == NULL) {
        throw std::runtime_error("Failed to create SDL window");
    }
}

void SDLWindowAdapter::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        boost::shared_ptr<SDLPayload> sdlPayload(new SDLPayload(event));
        SDLPayload *pSDLPayload = sdlPayload.get();

        boost::shared_ptr<SDLEvent> sdlEvent(new SDLEvent(*pSDLPayload));

        this->dispatcher.dispatchEvent("event.sdl", sdlEvent);
    }
}

std::string SDLWindowAdapter::getName()
{
    return "sdl";
}

SDLWindowAdapter::~SDLWindowAdapter()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}