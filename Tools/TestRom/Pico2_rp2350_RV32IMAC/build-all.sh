#!/usr/bin/env zsh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

for TEST_NUMBER in {00..11}; do
  rm -fr build
  cmake -S . -B build -DUSE_LLVM=ON -DTEST_NUMBER=$TEST_NUMBER
  cmake --build build
  print
done
rm -fr build
