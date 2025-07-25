cmake_minimum_required(VERSION 3.15)
project(PlatformGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
find_package(box2d REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Game.cpp
    src/Map.cpp
    src/Player.cpp
    src/Renderer.cpp
    src/Camera.cpp
    src/Resources.cpp
)

add_definitions(-DASSETS_PATH="${CMAKE_SOURCE_DIR}/assets")

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    box2d::box2d
)