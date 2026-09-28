set shell := ["bash", "-cu"]

default:
  @just --list

# Configure dev preset
configure:
  cmake --preset dev

# Build dev preset
build: configure
  cmake --build --preset dev

# Configure and build release preset
release:
  cmake --preset rel
  cmake --build --preset rel

# Build and run tests
test: build
  ctest --preset dev

# Run sandbox or editor
run app:
  ./build/dev/bin/{{app}}

# Clean build output
clean:
  rm -rf build build-release

# Format source
fmt:
  find engine apps -name '*.cpp' -o -name '*.hpp' -o -name '*.h' | xargs clang-format -i

# Full check
check: build
  @echo "Engine built successfully"
