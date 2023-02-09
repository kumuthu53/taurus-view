#!/bin/bash

# Run the build script.
source build.sh

EXE=taurus-view

EXE_LOCATION=$PWD/build/$EXE

if [ ! -f "$EXE_LOCATION" ]; then
  echo "Error: Executable not found at $EXE_LOCATION"
  exit 1
fi

sudo cp EXE_LOCATION /usr/local/bin
sudo chmod +x /usr/local/bin/EXE

# Check if installation was successful.
if command -v EXE >/dev/null 2>&1; then
  echo "EXE was installed successfully."
else
  echo "Error: EXE was not installed successfully."
  exit 1
fi