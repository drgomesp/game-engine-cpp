#pragma once

#include <vector>

#include "Cargo.hpp"

namespace Fibula {
    namespace EventDispatcher {

        using namespace std;

        class Payload
        {
        protected:
            Cargo *cargo;
        public:
            inline void setCargo(Cargo *cargo)
            {
                this->cargo = cargo;
            }

            Cargo *getCargo() const
            {
                return cargo;
            }

            virtual ~Payload() {}
        };
    }
}
