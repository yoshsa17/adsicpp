#! /bin/bash

BUILD_DIR_NAME="build"

if [ ! -e ./*.cpp ]; then
  echo "Unable find source files (./*.cpp)" 1>&2
  exit 1
fi

if [ ! -e ./${BUILD_DIR_NAME} ]; then
  mkdir ${BUILD_DIR_NAME}
fi


cmake -S . -B ${BUILD_DIR_NAME}