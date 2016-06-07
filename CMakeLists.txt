cmake_minimum_required(VERSION 3.4)
project(Fibula)

include_directories(BEFORE include/ src/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2_image -framework OpenGL -std=c++14 -Wall -W -pedantic")

# GLM
find_package(GLM REQUIRED)

# GLEW
find_package(GLEW REQUIRED)

# SDL 2
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

set(SOURCE_FILES
    main.cpp
    include/Fibula/Core/Kernel.hpp
    include/Fibula/Core/KernelAwareListener.hpp
    include/Fibula/Bridge/SDLEventListener.hpp
    include/Fibula/Bridge/SDLEvent.hpp
    include/Fibula/EventDispatcher/Event.hpp
    include/Fibula/EventDispatcher/Listener.hpp
    include/Fibula/EventDispatcher/Dispatcher.hpp
    include/Fibula/EventDispatcher/Payload.hpp
    include/Fibula/EventDispatcher/Payload.hpp
    include/Fibula/Graphics/Window.hpp
    include/Fibula/Graphics/Drawable.hpp
    include/Fibula/Bridge/SDLPayload.hpp
    include/Fibula/Graphics/TileMapLayer.hpp
    include/Fibula/Graphics/Tile.hpp
    include/Fibula/EventDispatcher/EventHandler.hpp
    include/Fibula/Graphics/TileSet.hpp
    include/Fibula/Graphics/Texture.hpp
    include/Fibula/Graphics/TileMap.hpp

    src/Fibula/Bridge/SDLEventListener.cpp
    src/Fibula/Core/Kernel.cpp
    src/Fibula/EventDispatcher/Dispatcher.cpp
    src/Fibula/Graphics/Window.cpp
    src/Fibula/Graphics/Tile.cpp
    src/Fibula/Graphics/TileMapLayer.cpp
    src/Fibula/Graphics/TileSet.cpp
    src/Fibula/Graphics/Texture.cpp
    src/Fibula/Graphics/TileMap.cpp

    src/demo-game/Listeners/SDL/MousePositionListener.cpp
    src/demo-game/Listeners/SDL/MousePositionListener.hpp
    src/demo-game/Core/Kernel.cpp
    src/demo-game/Core/Kernel.cpp src/demo-game/Core/Kernel.hpp
    )

add_executable(Fibula ${SOURCE_FILES})

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(Fibula ${GLEW_LIBRARIES})
target_link_libraries(Fibula ${SDL2_LIBRARIES})

add_custom_target(valgrind)
