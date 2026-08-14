# Ritual

**Ritual** is a from-scratch game engine focused on control, performance, and a tightly integrated scripting experience.

Built primarily in C/C++ with an OpenGL renderer (Vulkan path planned), Ritual is designed to be the foundation for personal projects, experimental games, and tools. Scripting is handled by **[Cantrip](https://github.com/StormbringerDev/cantrip)** - a lightweight, embeddable language created specifically as Ritual's scripting layer.

> Status: Early / foundation stage. Core architecture and Cantrip integration are in active development.

## Goals

- **Ownership & control** - No black-box engine. Every system is intentional and modifiable.
- **Performance** - Lean core with a clear path to high-performance rendering and scripting (Cantrip -> bytecode -> JIT).
- **Enjoyable scripting** - Cantrip is designed to feel good to write while remaining embeddable and fast.
- **Linux-first** - Primary development target is Linux (Wayland/X11), with cross-platform support planned.
- **Learning vehicle** - Engine development as a deliberate study of systems programming, graphics, and language implementation.

## Planned Architecture

| Layer               | Technology                          | Notes                                          |
| ------------------- | ----------------------------------- | ---------------------------------------------- |
| Core                | C / C++                             | Memory, math, platform, utilities              |
| Rendering           | OpenGL (initial) -> Vulkan          | Immediate + retained mode paths                |
| Scripting           | Cantrip                             | Tree-walking -> bytecode VM -> JIT (Cranelift) |
| Platform            | GLFW / native + custom abstractions | Windowing, input, filesystem                   |
| Audio               | TBD (miniaudio / custom)            |                                                |
| Physics / Collision | TBD                                 |                                                |
| Tools               | Editor, asset pipeline              | Later stages                                   |

## Cantrip Integration

Cantrip is the official language for Ritual. It is developed in parallel and is intended to be deeply embedded:

- Fast iteration via TypeScript tree-walking interpreter
- Production path via Rust bytecode VM + planned JIT
- Designed for game scripting (entities, components, events, hot-reload friendly)

See the [Cantrip repository](https://github.com/StormbringerDev/cantrip) for language status, examples, and roadmap.

## Project Structure (planned)

```
ritual/
├── engine/                 # Core engine library
│   ├── core/
│   ├── render/
│   ├── platform/
│   └── scripting/          # Cantrip embedding layer
├── apps/
│   ├── editor/             # (future)
│   └── sandbox/            # Development / test applications
├── assets/
├── docs/
├── third_party/
└── CMakeLists.txt / build system
```

## Current status

- [x] Project definition & high-level architecture
- [x] Cantrip language (active development - see linked repo)
- [ ] Core engine scaffolding (window, input, basic render loop)
- [ ] OpenGL renderer prototype
- [ ] Cantrip embedding API
- [ ] Asset loading & basic scene system
- [ ] Editor / tooling

## Building

_Coming soon._  
Expected toolchain: CMake, C++17/20, OpenGL 4.x / Vulkan, GLFW (or equivalent).

## Related Projects

- **[Cantrip](https://github.com/StormbringerDev/cantrip)** - Scripting language for Ritual
- Earlier experiments and prototypes (Redot-based) informed the decision to build a custom engine

## License

GNU Lesser General Public License v3.0.

## Contributing

This is currently a personal/solo project. Issues and discussion are welcome once the foundation is public.

---

_The Ritual has begun._
