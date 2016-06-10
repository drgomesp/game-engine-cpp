#pragma once

namespace Fibula {
    namespace Core {
        class Kernel;
    }
}

#include <string>
#include <vector>

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/vec2.hpp>

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>
#include <Fibula/EventDispatcher/EventHandler.hpp>
#include <Fibula/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;
        using namespace glm;

        using Dispatcher = Fibula::EventDispatcher::Dispatcher;
        using EventHandler = Fibula::EventDispatcher::EventHandler;
        using Kernel = Fibula::Core::Kernel;
        using DrawableVector = vector<shared_ptr<Drawable>>;

        class Window : public Drawable, public EventHandler
        {
        protected:
            ivec2 size;
            const std::string &name;
            SDL_Window *innerWindow;
            SDL_Renderer *renderer;
            Dispatcher &dispatcher;
            DrawableVector drawables;

        public:
            Window(const std::string &name, const ivec2 &size, Dispatcher &dispatcher);

            virtual int setUp(Kernel *kernel);
            virtual void handleEvents() override;
            virtual void handleInputs();
            virtual void update();
            virtual void draw(SDL_Renderer* renderer = nullptr) override;
            virtual void cleanUp(SDL_Renderer* renderer = nullptr) override;

            SDL_Renderer *getRenderer() const
            {
                return this->renderer;
            }

            void addDrawable(shared_ptr<Drawable> drawable);
        };
    }

}
