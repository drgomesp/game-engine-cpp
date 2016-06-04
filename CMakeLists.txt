cmake_minimum_required(VERSION 3.4)
project(Fibula)

include_directories(BEFORE src/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2_image -std=c++14 -Wall -W -pedantic")

# GLM
find_package(GLM REQUIRED)

# SDL 2
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

set(SOURCE_FILES
    main.cpp
    src/demo-game/Listeners/SDL/MousePositionListener.cpp
    src/demo-game/Listeners/SDL/MousePositionListener.hpp
    src/demo-game/Core/Kernel.cpp
    src/demo-game/Core/Kernel.cpp src/demo-game/Core/Kernel.hpp

    src/Fibula/Core/Kernel.cpp
    src/Fibula/Core/Kernel.hpp
    src/Fibula/Core/KernelAwareListener.hpp

    src/Fibula/EventDispatcher/Event.hpp
    src/Fibula/EventDispatcher/Listener.hpp
    src/Fibula/EventDispatcher/Dispatcher.cpp
    src/Fibula/EventDispatcher/Dispatcher.hpp
    src/Fibula/EventDispatcher/Payload.hpp
    src/Fibula/EventDispatcher/Payload.hpp
    src/Fibula/EventDispatcher/EventHandler.hpp

    src/Fibula/Bridge/SDLEventListener.cpp
    src/Fibula/Bridge/SDLEventListener.hpp
    src/Fibula/Bridge/SDLEvent.hpp
    src/Fibula/Bridge/SDLPayload.hpp

    src/Fibula/Graphics/Window.cpp
    src/Fibula/Graphics/Window.hpp
    src/Fibula/Graphics/Drawable.hpp
    src/Fibula/Graphics/Tile.cpp src/Fibula/Graphics/Tile.hpp src/Fibula/Graphics/TileMapLayer.cpp src/Fibula/Graphics/TileMapLayer.hpp src/Fibula/Graphics/TileSet.cpp src/Fibula/Graphics/TileSet.hpp src/Fibula/Graphics/TileMap.cpp src/Fibula/Graphics/TileMap.hpp src/Fibula/Graphics/TileSetTexture.hpp src/Fibula/Graphics/TileSetTexture.cpp src/Fibula/Graphics/TileSetTexture.hpp src/Fibula/Graphics/RendererProvider.cpp src/Fibula/Graphics/RendererProvider.hpp)

add_executable(Fibula ${SOURCE_FILES})

include_directories(${GLM_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(Fibula ${SDL2_LIBRARIES})

add_custom_target(valgrind)
