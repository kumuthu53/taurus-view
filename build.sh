#!/bin/bash

build_dir=build

if [ ! -d "$build_dir" ]; then
  mkdir "$build_dir"
fi

(
  cd "$build_dir"

  # Run CMake to generate the makefiles
  cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"

  # Build the project using make
  make
)

