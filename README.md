# Mandelbrot set with SIMD optimizations

## Compiling

+ Tune parameters in [mandelbrot.h](include/mandelbrot.h)
    1. Select type of floating point number to use in calculations

        Uncomment line with type you want: float or double, and comment other line

        ```c
        #define MANDELBROT_FLOAT
        // #define MANDELBROT_DOUBLE
        ```

    2. Choose size of MM register

        ```c
        #define MM_SIZE 256    // size of current mm register
        ```

        + `128` - `xmm` registers provided with `SSE` instruction set. Almost all modern CPUs have that instruction set.
        + `256` - `ymm` registers --> `AVX/AVX2` instruction set. Again, chances high your processor supports it.
        + `512` - `zmm` registers --> `AVX512` instruction set. Check your processor specs (CPUID) for `AVX512` flags. Only high-end CPUs (often with iGPU) support it.

        Generally, higher = better, but you are free to try and find best option

    3. Choose number of packs with floats in mm registers to use in one iteration

        ```c
        #define MM_PACKS 2
        ```

        Doing more commands without jumps helps CPU to conveyorize intsructions and perform much faster. On AVX512 optimal number seems to be 5.

    4. Modern compilers are smart enough to convert loops into vector instructions. This parameter controls number of points processed simultaneously.

        ```c
        #define AUTO_VEC_PACK_SIZE 32
        ```

        Use __multiples__ of powers of 2 (4, 8, 16, ...)  

        Best results are often get when `AUTO_VEC_PACK_SIZE` is x2 or x4 of floats you can put in one MM register.

        + For example: `AVX2` -> `256 bits` + `float (32bits)` -> `8` floats in `ymm` ---> `AUTO_VEC_PACK_SIZE = 32`
+ Choose screen resolution and render function in [main.cpp](src/main.cpp)

    ```c
    const int WIDTH  = 1920;    // in pixels
    const int HEIGHT = 1080;
    const mandelbrotFunc_t mandelbrotRenderer = calculateMandelbrotOptimized;
    ```

    Note: WIDTH must be divisible by `AUTO_VEC_PACK_SIZE` and `MM_SIZE`/8. Otherwise program will change resolution to compatible in runtime.

    Available render functions:
  + `calculateMandelbrot` - no optimizations
  + `calculateMandelbrotOptimized` - manual optimization with SIMD intrinsics
  + `calculateMandelbrotAutoVec` - version optimized by compiler
+ Run

    ```bash
    mkdir build
    make
    ```

    In case of compilation error try to decrease `MM_SIZE`.

## Usage

```bash
./mandelbrot.exe
```

Controls:

+ Zoom with mouse wheel and move image while holding left mouse button
+ Alternative:
  + wasd - move image
  + up and down arrows: zoom in and out
+ Left and right arrows: decrease and increase number of iterations
+ Ctrl+C: copy current position and scale to the clipboard
+ Ctrl+V: paste position and scale from clipboard
+ Escape: close

Test mode:

Pass number of tests as argument in command line. Result will be appended to the `tests.md`.

## Performance comparison

Test device: Lenovo XiaoXin X16 Pro (2024)

CPU: AMD Ryzen 7 8845H w/ Radeon 780M Graphics   3.80 GHz



