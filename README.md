# PlatformGame

A 2‑D platformer prototype written in modern C++ 17, powered by **SFML 2.6.2** for rendering and **Box2D 3.1.0** for physics.  
The project is built with **CMake** and uses **Conan 2** to fetch and manage third‑party libraries.

---

## Prerequisites

| Tool            | Version (tested) | Notes                                  |
|-----------------|------------------|----------------------------------------|
| **CMake**       | ≥ 3.15           | Multi‑config generator recommended     |
| **Conan**       | 2.x              | Package/dependency manager             |
| **Visual Studio** | 2022 (v17)      | Includes MSVC v143 toolset & SDK 10.0+ |
| **Git**         | any              | (optional) clone & contribute          |

> macOS / Linux users can replace Visual Studio with `clang` or `g++` and tweak the generator names accordingly.

---

## How to Run

From the project root:

```bash
.\setup_project.bat           # Builds Debug (default)
.\setup_project.bat Release   # Builds Release
```

The script will:
1. Delete/re‑create `build/`
2. conan install → downloads SFML + Box2D
3. cmake configure → generates a VS solution under build/
4. cmake --build → compiles PlatformGame.exe

You’ll find the executable at:
`build\<Debug|Release>\PlatformGame.exe`

---

## Manual build (any platform)

```bash
# Inside project root
mkdir build && cd build

# Fetch dependencies (example: Debug)
conan install .. -of . --build=missing -s build_type=Debug

# Configure CMake with Conan’s toolchain
cmake -G "Ninja" \
      -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake \
      -DCMAKE_BUILD_TYPE=Debug \
      -S .. -B .

# Build
cmake --build . # or ninja
```