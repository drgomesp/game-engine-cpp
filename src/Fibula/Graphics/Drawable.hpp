#ifndef FIBULA_DRAWABLE_HPP
#define FIBULA_DRAWABLE_HPP

namespace Fibula {
    namespace Graphics {
        class Drawable
        {
            virtual void draw() = 0;
            virtual void cleanUp() = 0;
        };
    }
}


#endif //FIBULA_DRAWABLE_HPP
