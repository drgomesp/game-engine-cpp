#ifndef GAME_KERNEL_HPP
#define GAME_KERNEL_HPP

#include <Fibula/Core/Kernel.hpp>

namespace Game {
    namespace Core {
        class Kernel : public Fibula::Core::Kernel
        {
        protected:
            const std::string &name;
        public:
            Kernel(const std::string &name) : name(name)
            { }

            virtual void registerListeners() override;
        };
    }
}

#endif //FIBULA_KERNEL_HPP
