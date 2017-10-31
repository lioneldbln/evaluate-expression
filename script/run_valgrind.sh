#!/bin/bash

RED="\033[0;31m"
NC="\033[0m" # No Color

cd ./build

cmake -DCMAKE_BUILD_TYPE=Debug ..

make
if [ "$?" -ne 0 ]; then echo -e "${RED}compilation failed!${NC}"; exit 1; fi

./tests/evalexptests

valgrind --leak-check=yes ./evalexp

