configure:
  cmake --preset dev

build: configure
  cmake --build --preset dev

release:
  cmake --preset rel
  cmake --build --preset rel

run-sandbox: build
  ./build/dev/apps/sandbox/sandbox

test: build
  ctest --preset dev

clean:
  rm -rf build