# Ritual - common commands

set shell := ["bash", "-cu"]

default:
    @just --list

# Configure + build (Debug)
configure:
    cmake --preset dev

build: configure
    cmake --build --preset dev

# Release build
release:
    cmake --preset rel
    cmake --build --preset rel

# Run tests
test: build
    ctest --preset dev

# Run a specific example (e.g. just run 01_hello_window)
run name:
    ./build/dev/bin/{{name}}

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