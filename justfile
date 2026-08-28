# Ritual - common commands

set shell := ["bash", "-cu"]

default:
    @just --list

# Configure + build (Debug)
configure:
    cmake -B build -G Ninja \
      -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_TOOLCHAIN_FILE="{{env('VCPKG_ROOT')}}/scripts/buildsystems/vcpkg.cmake"

build: configure
    cmake --build build

# Release build
release:
    cmake -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release
    cmake --build build-release

# Run a specific example (e.g. just run 01_hello_window)
run name:
    ./build/bin/{{name}}

# Clean
clean:
    rm -rf build build-release

# Format
fmt:
    find engine apps -name '*.cpp' -o -name '*.hpp' -o -name '*.h' | xargs clang-format -i

# Cantrip helpers
cantrip-build:
    cd cantrip && cargo build

cantrip-test:
    cd cantrip && cargo test

# Full check
check: build
    @echo "Engine built successfully"