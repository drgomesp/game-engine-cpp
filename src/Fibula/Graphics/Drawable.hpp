#ifndef FIBULA_DRAWABLE_HPP
#define FIBULA_DRAWABLE_HPP

namespace Fibula {
    namespace Graphics {
        class Drawable
        {
        protected:
            SDL_Renderer *renderer;
            SDL_Window *window;
        public:
            virtual void draw() = 0;
            virtual void cleanUp() = 0;

            SDL_Renderer *getRenderer() const
            {
                return renderer;
            }

            void setRenderer(SDL_Renderer *renderer)
            {
                Drawable::renderer = renderer;
            }

            SDL_Window *getWindow() const
            {
                return window;
            }

            void setWindow(SDL_Window *window)
            {
                Drawable::window = window;
            }

            bool ready()
            {
                return this->renderer == nullptr || this->window == nullptr;
            }
        };
    }
}


#endif //FIBULA_DRAWABLE_HPP
