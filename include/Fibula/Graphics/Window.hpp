#pragma once

namespace Fibula {
    namespace Core {
        class Kernel;
    }
}

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "../Core/Kernel.hpp"
#include "../EventDispatcher/Dispatcher.hpp"
#include "../EventDispatcher/EventHandler.hpp"
#include "Drawable.hpp"

namespace Fibula {
    namespace Graphics {

        using namespace boost;
        using namespace glm;

        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using EventHandler = Fibula::EventDispatcher::EventHandler;
        using Kernel = Fibula::Core::Kernel;
        using DrawableVector = ptr_vector<Drawable>;

        class Window : public Drawable, public EventHandler
        {
        protected:
            SDL_Window *innerWindow;
            SDL_Renderer *renderer;
            Dispatcher &dispatcher;
            const std::string name;
            ivec2 size;
            DrawableVector drawables;

        public:
            Window(const std::string name, const ivec2 &size, Dispatcher &dispatcher);

            virtual int setUp(Kernel *kernel);
            virtual void handleEvents() override;
            virtual void draw(SDL_Renderer* renderer = nullptr) override;
            virtual void cleanUp(SDL_Renderer* renderer = nullptr) override;

            SDL_Window *getInnerWindow() const
            {
                return this->innerWindow;
            }

            SDL_Renderer *getRenderer() const
            {
                return this->renderer;
            }

            void addDrawable(Drawable *drawable);
        };
    }

}
