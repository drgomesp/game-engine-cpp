#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

namespace Fibula {
    namespace Core {

        using namespace std;
        using State = Fibula::Core::State;

        class StateManager
        {
        protected:
            stack<shared_ptr<State>> states;
        public:
            void change(shared_ptr<State> state);
            void push(shared_ptr<State> state);
            void pop();
        };
    }
}
