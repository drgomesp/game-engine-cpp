#include <Fibula/Core/StateManager.hpp>

using namespace Fibula::Core;

void StateManager::change(shared_ptr<State> state)
{

}

void StateManager::push(shared_ptr<State> state)
{
    this->states.push(state);
}

void StateManager::pop()
{
    this->states.pop();
}
