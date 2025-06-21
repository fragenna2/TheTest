## TheTest
First game made with SDL2. It was developed on Linux it uses Cmake

## Documentation

To compile, first download the project from github. After execute:

```Bash
cmake -S . -B build
```
To specify which is the build folder. Before compiling check if in the CMakeLists.txt the option "PRODUCTION_BUILD" is turned ON. Then compile the game with:
```Bash
cmake -DCMAKE_BUILD_TYPE=Release -B build
```
```Bash
cmake -build build
```

It should compile without errors
