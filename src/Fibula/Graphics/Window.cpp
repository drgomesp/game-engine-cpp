#include "../../../include/Fibula/Graphics/Window.hpp"

#include <iostream>

#include "../../../include/Fibula/Bridge/SDLEventListener.hpp"
#include "../../../include/Fibula/Graphics/Texture.hpp"
#include "../../../include/Fibula/Graphics/TileSet.hpp"

using namespace std;
using namespace Fibula::Bridge;
using namespace Fibula::Graphics;

Window::Window(const string name, const ivec2 &size, Dispatcher &dispatcher)
    : name(name), size(size), dispatcher(dispatcher)
{
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw runtime_error("Failed to initialize SDL");
    }

    window = SDL_CreateWindow(
        name.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->size.x,
        this->size.y,
        SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL
    );

    this->innerWindow = window;

    if (NULL == this->innerWindow) {
        SDL_Quit();
        throw runtime_error("Failed to create SDL window");
    }

    this->renderer = SDL_CreateRenderer(this->innerWindow, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == this->renderer) {
        throw runtime_error(SDL_GetError());
    }

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

int Window::setUp(Kernel *kernel)
{
    std::shared_ptr<SDLEventListener> listener = make_shared<SDLEventListener>(kernel);
    this->dispatcher.addListener("event.sdl", listener);

    kernel->running = true;
    return EXIT_SUCCESS;
}

void Window::draw(SDL_Renderer* renderer)
{
    for (shared_ptr<Drawable> drawable : this->drawables) {
        SDL_RenderClear(this->renderer);
        drawable->draw(this->renderer);
        SDL_RenderPresent(this->renderer);
    }
}

void Window::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        std::shared_ptr<SDLPayload> payload = make_shared<SDLPayload>(event);
        std::shared_ptr<const SDLEvent> e = make_shared<const SDLEvent>(*payload);

        this->dispatcher.dispatchEvent("event.sdl", e);
    }
}

void Window::cleanUp(SDL_Renderer* renderer)
{
    for (shared_ptr<Drawable> drawable : this->drawables) {
        drawable->cleanUp(renderer);
    }

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->innerWindow);
    SDL_Quit();
}

void Window::addDrawable(shared_ptr<Drawable> drawable)
{
    this->drawables.push_back(drawable);
}
