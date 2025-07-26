cmake_minimum_required(VERSION 3.15)
project(PlatformGame LANGUAGES CXX)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR
        "You must pass -DCMAKE_TOOLCHAIN_FILE=<build-dir>/conan_toolchain.cmake when invoking CMake "
        "(run Conan first; see guide below).")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Game.cpp
    src/Map.cpp
    src/Player.cpp
    src/Renderer.cpp
    src/Camera.cpp
    src/Resources.cpp
    src/Physics.cpp
)

# Asset path available at compile time
target_compile_definitions(${PROJECT_NAME}
    PRIVATE ASSETS_PATH=\"${CMAKE_SOURCE_DIR}/assets\"
)

# Libraries provided by Conan‑generated CMake files
find_package(sfml COMPONENTS graphics window system REQUIRED)
find_package(box2d REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        box2d::box2d
)
