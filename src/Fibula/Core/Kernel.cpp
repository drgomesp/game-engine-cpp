#include <memory>
#include <iostream>

#include <glm/vec2.hpp>
#include <Fibula/Core/Kernel.hpp>

using namespace glm;
using namespace std;
using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;

void Kernel::addListener(const std::string &eventName, std::shared_ptr<Listener> listener)
{
    this->dispatcher->addListener(eventName, listener);
}

void Kernel::bootstrap()
{
    this->dispatcher = make_shared<Dispatcher>();
    this->window = make_shared<Window>(
        "Fibula Engine :: v1.0.0",
        vec2(1280, 768),
        *this->dispatcher
    );

    if (NULL == this->window) {
        throw runtime_error("Failed to create window");
    }

    cout << "Engine successfully started" << endl;

    this->booted = true;
}

void Kernel::run()
{
    this->bootstrap();
    this->registerListeners();

    if (!this->booted) {
        throw runtime_error("Failed to run engine because it was never booted");
    }

    this->running = true;

    this->window->setUp(this);

    while (this->running) {
        this->window->draw();
        this->window->handleEvents();
    }

    this->window->cleanUp();
}

void Kernel::terminate()
{
    this->running = false;
}
