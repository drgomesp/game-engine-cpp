#pragma once

#include <Fibula/EventDispatcher/EventHandler.hpp>
#include <Fibula/Input/InputHandler.hpp>
#include <Fibula/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Core {

        using Drawable = Fibula::Graphics::Drawable;
        using EventHandler = Fibula::EventDispatcher::EventHandler;
        using InputHandler = Fibula::Input::InputHandler;

        class State : public Drawable, public EventHandler, public InputHandler
        {
        protected:
            State()
            { }

        public:
            virtual void init() = 0;

            virtual void pause() = 0;
            virtual void resume() = 0;

            virtual void handleEvents() override = 0;
            virtual void draw(SDL_Renderer *renderer) override = 0;
            virtual void cleanUp(SDL_Renderer *renderer) override = 0;
            virtual void handleInput() override = 0;
            virtual void update() = 0;
        };
    }
}
