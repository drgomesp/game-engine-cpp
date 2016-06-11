cmake_minimum_required(VERSION 3.5)
project(Fibula)

message(STATUS "Fibula Version: ")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2_image -lGL -lGLEW -std=c++14 -Wall -pedantic")

set(FIBULA_INCLUDE_DIR "include/Fibula")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})

include_directories(
        ${FIBULA_INCLUDE_DIR}
)

# This stuff needed to put every include file into needed directory when we do make install
file(GLOB BRIDGE
        ${FIBULA_INCLUDE_DIR}/Bridge/*.hpp
        )
file(GLOB CORE
        ${FIBULA_INCLUDE_DIR}/Core/*.hpp
        )
file(GLOB DEBUG
        ${FIBULA_INCLUDE_DIR}/Debug/*.hpp
        )
file(GLOB EVENT
        ${FIBULA_INCLUDE_DIR}/EventDispatcher/*.hpp
        )
file(GLOB GRAPHICS
        ${FIBULA_INCLUDE_DIR}/Graphics/*.hpp
        )
file(GLOB INPUT
        ${FIBULA_INCLUDE_DIR}/Input/*.hpp
        )

file(GLOB_RECURSE SOURCE_LIST
        src/*.cpp
        )

set(HEADER_LIST
        ${BRIDGE}
        ${CORE}
        ${DEBUG}
        ${EVENT}
        ${GRAPHICS}
        ${INPUT}
        )

# GLM
find_package(GLM REQUIRED)
if(NOT GLM_FOUND)
    message(SEND_ERROR "Failed to find GLM")
    return()
else()
    include_directories(${GLM_INCLUDE_DIRS})
endif()


# GLEW
find_package(GLEW REQUIRED)
if(NOT GLEW_FOUND)
    message(SEND_ERROR "Failed to find GLEW")
    return()
else()
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

# SDL 2
find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
    message(SEND_ERROR "Failed to find SDL2")
    return()
else()
    string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

add_library(Fibula SHARED ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(Fibula
        ${GLM_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${SDL2_LIBARIES}
        )

# When we do 'make install' it will put .so file into lib directory and include files into include directory
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib/${PROJECT_NAME})
install(FILES ${BRIDGE} DESTINATION include/${PROJECT_NAME}/Bridge/)
install(FILES ${CORE} DESTINATION include/${PROJECT_NAME}/Core/)
install(FILES ${DEBUG} DESTINATION include/${PROJECT_NAME}/Debug/)
install(FILES ${EVENT} DESTINATION include/${PROJECT_NAME}/EventDispatcher/)
install(FILES ${GRAPHICS} DESTINATION include/${PROJECT_NAME}/Graphics/)
install(FILES ${INPUT} DESTINATION include/${PROJECT_NAME}/Input/)