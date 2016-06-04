#include <iostream>
#include <demo-game/Core/Kernel.hpp>

using namespace std;

int main() {
    Game::Core::Kernel game("sdl");

    try {
        game.run();
    } catch (exception const &e) {
        game.terminate();
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
