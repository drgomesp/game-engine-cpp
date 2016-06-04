#ifndef FIBULA_WINDOW_HPP
#define FIBULA_WINDOW_HPP

namespace Fibula {
    namespace Core {
        class Kernel;
    }
}

#include <string>
#include <memory>
#include <vector>

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <Fibula/EventDispatcher/EventHandler.hpp>
#include <Fibula/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace glm;
        using namespace std;

        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using EventHandler = Fibula::EventDispatcher::EventHandler;
        using Kernel = Fibula::Core::Kernel;
        using DrawableVector = vector<shared_ptr<Drawable>>;

        class Window : public Drawable, public EventHandler
        {
        protected:
            SDL_Window *innerWindow;
            SDL_Renderer *renderer;
            Dispatcher &dispatcher;
            const string name;
            ivec2 size;
            DrawableVector drawables;

        public:
            Window(const string name, const ivec2 &size, Dispatcher &dispatcher);

            virtual void draw(SDL_Renderer *renderer) override;
            virtual int setUp(Kernel *kernel);
            virtual void handleEvents() override;
            virtual void cleanUp(SDL_Renderer *renderer) override;

            void addDrawable(shared_ptr<Drawable> drawable);
        };
    }

}


#endif //FIBULA_WINDOW_HPP
