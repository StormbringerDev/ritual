# Ritual

Ritual is a from-scratch game engine designed for 3D game development. The engine is planned to include the [Cantrip](https://github.com/StormbringerDev/cantrip) scripting layer for game logic.

## Getting Started

### Prerequisites

- A C/C++ compiler (GCC, Clang, MSVC, etc.) that supports C++20
- CMake version 3.20 or higher
- Ninja
- Just for convenience commands (optional — read `justfile` for commands)

### Installation

```bash
# 1. Clone the repository
git clone https://github.com/StormbringerDev/ritual
cd ritual

# 2. Build the engine
# with just
just build
# without just
cmake --preset dev
cmake --build --preset dev
```

### Usage

Currently only exists as a sandbox:

```bash
# with just
just run-sandbox
# without just
./build/dev/apps/sandbox
```

## Roadmap

- GLFW3 windowing — Simple window creation before creating windows natively.
- OpenGL rendering — Planned rendering backend before Vulkan.
- Cantrip game logic — Creation of game logic with the [Cantrip](https://github.com/StormbringerDev/cantrip) scripting language.
- Jolt physics — Integration of the Jolt physics library for performant physics simulation.
- Multiplatform — Prioritizing Linux with Windows support planned.

## License

GNU Lesser General Public License v3.0.