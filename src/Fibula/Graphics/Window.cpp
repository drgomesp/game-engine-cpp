#include <Fibula/Graphics/Window.hpp>

#include <iostream>

#include <Fibula/Bridge/SDLEventListener.hpp>
#include <Fibula/Graphics/Texture.hpp>
#include <Fibula/Graphics/TileSet.hpp>

using namespace std;
using namespace Fibula::Bridge;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics;

Window::Window(const string &name, const ivec2 &size, Dispatcher &dispatcher)
    : name(name), size(size), dispatcher(dispatcher)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw runtime_error("Failed to initialize SDL");
    }

    SDL_Window *window;

    // Use OpenGL 4.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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

    SDL_GLContext context = SDL_GL_CreateContext(this->innerWindow);

    if (NULL == context) {
        SDL_Quit();
        throw runtime_error("Failed to create OpenGL context");
    }

    printf("OpenGL context successfully initialized :: %s\n", glGetString(GL_VERSION));

    GLenum error = glewInit();

    if (GLEW_OK != error) {
        throw runtime_error("Failed to initialize GLEW");
    }

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);


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
        for (shared_ptr<Drawable> drawable : this->drawables) {
            std::shared_ptr<SDLPayload> payload = make_shared<SDLPayload>(event);

            if (Cargo *cargo = dynamic_cast<Cargo *>(drawable.get())) {
                payload->setCargo(cargo);
            } else {
                payload->setCargo(nullptr);
            }

            std::shared_ptr<SDLEvent> e = make_shared<SDLEvent>(*payload);
            this->dispatcher.dispatchEvent("event.sdl", e);
        }
    }
}

void Window::handleInputs()
{

}

void Window::update()
{

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
