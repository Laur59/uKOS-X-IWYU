# Using gcc

```
rm -r build
cmake -S . -B build -DTEST_NUMBER=00
cmake --build build
cmake --build build --target burn
cmake --build build --target clr_all
```

# using clang

```

rm -r build 
cmake -S . -B build -DUSE_LLVM=ON -DTEST_NUMBER=00
cmake --build build                 
cmake --build build --target burn   
cmake --build build --target clr_all
```
