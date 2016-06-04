#include "Window.hpp"

#include <iostream>

#include <Fibula/Bridge/SDLEventListener.hpp>

using namespace Fibula::Bridge;
using namespace Fibula::Graphics;

Window::Window(const string &name, const ivec2 &size, Dispatcher &dispatcher)
    : name(name), size(size), dispatcher(dispatcher)
{
    SDL_Window *window;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
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
    this->renderer = SDL_CreateRenderer(this->innerWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    if (NULL == this->innerWindow) {
        SDL_Quit();
        throw runtime_error("Failed to create SDL window");
    }
}

int Window::setUp(Kernel *kernel)
{
    shared_ptr<SDLEventListener> listener = make_shared<SDLEventListener>(kernel);
    this->dispatcher.addListener("event.sdl", listener);

    return EXIT_SUCCESS;
}

void Window::draw()
{

}

void Window::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        shared_ptr<SDLPayload> payload = make_shared<SDLPayload>(event);
        shared_ptr<const SDLEvent> e = make_shared<const SDLEvent>(*payload);

        this->dispatcher.dispatchEvent("event.sdl", e);
    }
}

void Window::cleanUp()
{
    SDL_DestroyWindow(this->innerWindow);
    SDL_Quit();
}

void Window::addDrawable(shared_ptr<Drawable> drawable)
{
    drawable->setRenderer(this->renderer);

    this->drawables.resize(sizeof(drawable));
    this->drawables.push_back(drawable);
}
