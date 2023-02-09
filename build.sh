#!/bin/bash

build_dir=build

if [ ! -d "$build_dir" ]; then
  mkdir "$build_dir"
fi

(
  cd "$build_dir"

  # Run CMake to generate the makefiles
  cmake ..

  # Build the project using make
  make
)

