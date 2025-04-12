
# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 1
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $252.993 \pm 0.474$
 + Best  frame: 249.24 ms
 + Worst frame: 260.50 ms


## Intrinsic optimizations
 + Number of tests: 92
 + FPS: 15.24
 + Milliseconds per frame: $65.600 \pm 0.107$
 + Best  frame: 64.16 ms
 + Worst frame: 68.04 ms


## Automatic vectorization by compiler
 + Number of tests: 341
 + FPS: 56.80
 + Milliseconds per frame: $17.607 \pm 0.025$
 + Best  frame: 17.17 ms
 + Worst frame: 19.42 ms


## Intrinsics on 4 threads
 + Number of tests: 356
 + FPS: 59.24
 + Milliseconds per frame: $16.880 \pm 0.026$
 + Best  frame: 16.39 ms
 + Worst frame: 18.83 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 2
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.615 \pm 0.392$
 + Best  frame: 247.22 ms
 + Worst frame: 256.82 ms


## Intrinsic optimizations
 + Number of tests: 148
 + FPS: 24.66
 + Milliseconds per frame: $40.547 \pm 0.058$
 + Best  frame: 39.75 ms
 + Worst frame: 42.38 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.01
 + Milliseconds per frame: $17.540 \pm 0.023$
 + Best  frame: 17.16 ms
 + Worst frame: 19.18 ms


## Intrinsics on 4 threads
 + Number of tests: 563
 + FPS: 93.64
 + Milliseconds per frame: $10.679 \pm 0.016$
 + Best  frame: 10.21 ms
 + Worst frame: 12.55 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 3
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $252.860 \pm 0.447$
 + Best  frame: 250.08 ms
 + Worst frame: 260.69 ms


## Intrinsic optimizations
 + Number of tests: 185
 + FPS: 30.71
 + Milliseconds per frame: $32.560 \pm 0.045$
 + Best  frame: 31.90 ms
 + Worst frame: 34.47 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 57.00
 + Milliseconds per frame: $17.544 \pm 0.024$
 + Best  frame: 17.17 ms
 + Worst frame: 19.30 ms


## Intrinsics on 4 threads
 + Number of tests: 664
 + FPS: 110.64
 + Milliseconds per frame: $9.038 \pm 0.012$
 + Best  frame: 8.73 ms
 + Worst frame: 10.78 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 4
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.669 \pm 0.438$
 + Best  frame: 247.71 ms
 + Worst frame: 258.27 ms


## Intrinsic optimizations
 + Number of tests: 199
 + FPS: 33.02
 + Milliseconds per frame: $30.281 \pm 0.046$
 + Best  frame: 29.60 ms
 + Worst frame: 32.09 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.96
 + Milliseconds per frame: $17.557 \pm 0.024$
 + Best  frame: 17.17 ms
 + Worst frame: 19.42 ms


## Intrinsics on 4 threads
 + Number of tests: 753
 + FPS: 125.49
 + Milliseconds per frame: $7.969 \pm 0.011$
 + Best  frame: 7.58 ms
 + Worst frame: 9.65 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 4
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $253.236 \pm 0.362$
 + Best  frame: 250.35 ms
 + Worst frame: 258.02 ms


## Intrinsic optimizations
 + Number of tests: 197
 + FPS: 32.75
 + Milliseconds per frame: $30.532 \pm 0.051$
 + Best  frame: 29.72 ms
 + Worst frame: 32.53 ms


## Automatic vectorization by compiler
 + Number of tests: 341
 + FPS: 56.75
 + Milliseconds per frame: $17.622 \pm 0.026$
 + Best  frame: 17.20 ms
 + Worst frame: 19.41 ms


## Intrinsics on 4 threads
 + Number of tests: 748
 + FPS: 124.64
 + Milliseconds per frame: $8.023 \pm 0.010$
 + Best  frame: 7.79 ms
 + Worst frame: 9.70 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 5
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.671 \pm 0.462$
 + Best  frame: 244.57 ms
 + Worst frame: 255.56 ms


## Intrinsic optimizations
 + Number of tests: 220
 + FPS: 36.63
 + Milliseconds per frame: $27.303 \pm 0.041$
 + Best  frame: 26.72 ms
 + Worst frame: 29.22 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.03
 + Milliseconds per frame: $17.534 \pm 0.024$
 + Best  frame: 17.17 ms
 + Worst frame: 19.76 ms


## Intrinsics on 4 threads
 + Number of tests: 834
 + FPS: 138.95
 + Milliseconds per frame: $7.197 \pm 0.010$
 + Best  frame: 6.86 ms
 + Worst frame: 8.89 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.438 \pm 0.357$
 + Best  frame: 246.19 ms
 + Worst frame: 255.00 ms


## Intrinsic optimizations
 + Number of tests: 233
 + FPS: 38.70
 + Milliseconds per frame: $25.840 \pm 0.042$
 + Best  frame: 25.19 ms
 + Worst frame: 27.79 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.88
 + Milliseconds per frame: $17.580 \pm 0.024$
 + Best  frame: 17.16 ms
 + Worst frame: 19.33 ms


## Intrinsics on 4 threads
 + Number of tests: 869
 + FPS: 144.78
 + Milliseconds per frame: $6.907 \pm 0.010$
 + Best  frame: 6.65 ms
 + Worst frame: 8.85 ms

# Test session
## General information:
```
RESOLUTION: 2016x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 7
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 22
 + FPS: 3.64
 + Milliseconds per frame: $275.048 \pm 0.414$
 + Best  frame: 272.54 ms
 + Worst frame: 281.09 ms


## Intrinsic optimizations
 + Number of tests: 189
 + FPS: 31.44
 + Milliseconds per frame: $31.805 \pm 0.063$
 + Best  frame: 30.81 ms
 + Worst frame: 34.06 ms


## Automatic vectorization by compiler
 + Number of tests: 314
 + FPS: 52.19
 + Milliseconds per frame: $19.161 \pm 0.029$
 + Best  frame: 18.74 ms
 + Worst frame: 21.18 ms


## Intrinsics on 4 threads
 + Number of tests: 714
 + FPS: 118.89
 + Milliseconds per frame: $8.411 \pm 0.013$
 + Best  frame: 8.13 ms
 + Worst frame: 10.37 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 8
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 22
 + FPS: 3.54
 + Milliseconds per frame: $282.589 \pm 0.385$
 + Best  frame: 279.24 ms
 + Worst frame: 287.50 ms


## Intrinsic optimizations
 + Number of tests: 169
 + FPS: 28.06
 + Milliseconds per frame: $35.644 \pm 0.060$
 + Best  frame: 34.88 ms
 + Worst frame: 37.66 ms


## Automatic vectorization by compiler
 + Number of tests: 304
 + FPS: 50.62
 + Milliseconds per frame: $19.756 \pm 0.029$
 + Best  frame: 19.34 ms
 + Worst frame: 21.45 ms


## Intrinsics on 4 threads
 + Number of tests: 631
 + FPS: 105.02
 + Milliseconds per frame: $9.522 \pm 0.015$
 + Best  frame: 9.15 ms
 + Worst frame: 11.61 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 1
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.678 \pm 0.372$
 + Best  frame: 247.40 ms
 + Worst frame: 255.55 ms


## Intrinsic optimizations
 + Number of tests: 179
 + FPS: 29.83
 + Milliseconds per frame: $33.527 \pm 0.047$
 + Best  frame: 32.85 ms
 + Worst frame: 35.52 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.03
 + Milliseconds per frame: $17.536 \pm 0.023$
 + Best  frame: 17.13 ms
 + Worst frame: 19.39 ms


## Intrinsics on 4 threads
 + Number of tests: 693
 + FPS: 115.49
 + Milliseconds per frame: $8.659 \pm 0.012$
 + Best  frame: 8.39 ms
 + Worst frame: 10.66 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 2
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 4.00
 + Milliseconds per frame: $250.061 \pm 0.503$
 + Best  frame: 245.21 ms
 + Worst frame: 257.09 ms


## Intrinsic optimizations
 + Number of tests: 286
 + FPS: 47.54
 + Milliseconds per frame: $21.037 \pm 0.029$
 + Best  frame: 20.59 ms
 + Worst frame: 22.82 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.93
 + Milliseconds per frame: $17.564 \pm 0.024$
 + Best  frame: 17.14 ms
 + Worst frame: 19.34 ms


## Intrinsics on 4 threads
 + Number of tests: 1084
 + FPS: 180.57
 + Milliseconds per frame: $5.538 \pm 0.007$
 + Best  frame: 5.30 ms
 + Worst frame: 7.27 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 3
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.489 \pm 0.314$
 + Best  frame: 248.05 ms
 + Worst frame: 253.64 ms


## Intrinsic optimizations
 + Number of tests: 348
 + FPS: 57.93
 + Milliseconds per frame: $17.262 \pm 0.027$
 + Best  frame: 16.89 ms
 + Worst frame: 19.16 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.91
 + Milliseconds per frame: $17.572 \pm 0.027$
 + Best  frame: 17.20 ms
 + Worst frame: 19.43 ms


## Intrinsics on 4 threads
 + Number of tests: 1248
 + FPS: 207.99
 + Milliseconds per frame: $4.808 \pm 0.006$
 + Best  frame: 4.57 ms
 + Worst frame: 6.55 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 4
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 22
 + FPS: 3.53
 + Milliseconds per frame: $283.439 \pm 0.380$
 + Best  frame: 281.27 ms
 + Worst frame: 287.71 ms


## Intrinsic optimizations
 + Number of tests: 337
 + FPS: 56.03
 + Milliseconds per frame: $17.847 \pm 0.027$
 + Best  frame: 17.49 ms
 + Worst frame: 19.98 ms


## Automatic vectorization by compiler
 + Number of tests: 304
 + FPS: 50.58
 + Milliseconds per frame: $19.772 \pm 0.029$
 + Best  frame: 19.35 ms
 + Worst frame: 21.50 ms


## Intrinsics on 4 threads
 + Number of tests: 1267
 + FPS: 211.15
 + Milliseconds per frame: $4.736 \pm 0.006$
 + Best  frame: 4.52 ms
 + Worst frame: 6.48 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 5
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.679 \pm 0.368$
 + Best  frame: 245.30 ms
 + Worst frame: 255.33 ms


## Intrinsic optimizations
 + Number of tests: 412
 + FPS: 68.62
 + Milliseconds per frame: $14.574 \pm 0.024$
 + Best  frame: 14.17 ms
 + Worst frame: 16.46 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.91
 + Milliseconds per frame: $17.572 \pm 0.027$
 + Best  frame: 17.17 ms
 + Worst frame: 19.50 ms


## Intrinsics on 4 threads
 + Number of tests: 1558
 + FPS: 259.61
 + Milliseconds per frame: $3.852 \pm 0.005$
 + Best  frame: 3.66 ms
 + Worst frame: 5.59 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.777 \pm 0.442$
 + Best  frame: 248.82 ms
 + Worst frame: 259.23 ms


## Intrinsic optimizations
 + Number of tests: 435
 + FPS: 72.36
 + Milliseconds per frame: $13.819 \pm 0.023$
 + Best  frame: 13.41 ms
 + Worst frame: 15.74 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.94
 + Milliseconds per frame: $17.562 \pm 0.027$
 + Best  frame: 17.17 ms
 + Worst frame: 19.58 ms


## Intrinsics on 4 threads
 + Number of tests: 1630
 + FPS: 271.59
 + Milliseconds per frame: $3.682 \pm 0.005$
 + Best  frame: 3.50 ms
 + Worst frame: 5.56 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.505 \pm 0.397$
 + Best  frame: 250.24 ms
 + Worst frame: 259.29 ms


## Intrinsic optimizations
 + Number of tests: 436
 + FPS: 72.52
 + Milliseconds per frame: $13.789 \pm 0.022$
 + Best  frame: 13.40 ms
 + Worst frame: 15.69 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 57.00
 + Milliseconds per frame: $17.544 \pm 0.026$
 + Best  frame: 17.17 ms
 + Worst frame: 19.48 ms


## Intrinsics on 4 threads
 + Number of tests: 1635
 + FPS: 272.48
 + Milliseconds per frame: $3.670 \pm 0.005$
 + Best  frame: 3.48 ms
 + Worst frame: 5.45 ms

# Test session
## General information:
```
RESOLUTION: 2240x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 7
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 18
 + FPS: 2.97
 + Milliseconds per frame: $336.666 \pm 0.622$
 + Best  frame: 331.86 ms
 + Worst frame: 342.51 ms


## Intrinsic optimizations
 + Number of tests: 293
 + FPS: 48.79
 + Milliseconds per frame: $20.498 \pm 0.036$
 + Best  frame: 19.89 ms
 + Worst frame: 22.50 ms


## Automatic vectorization by compiler
 + Number of tests: 259
 + FPS: 43.16
 + Milliseconds per frame: $23.167 \pm 0.035$
 + Best  frame: 22.68 ms
 + Worst frame: 25.15 ms


## Intrinsics on 4 threads
 + Number of tests: 1100
 + FPS: 183.32
 + Milliseconds per frame: $5.455 \pm 0.008$
 + Best  frame: 5.22 ms
 + Worst frame: 7.50 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 8
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 21
 + FPS: 3.49
 + Milliseconds per frame: $286.571 \pm 0.395$
 + Best  frame: 283.16 ms
 + Worst frame: 291.71 ms


## Intrinsic optimizations
 + Number of tests: 329
 + FPS: 54.67
 + Milliseconds per frame: $18.292 \pm 0.031$
 + Best  frame: 17.74 ms
 + Worst frame: 20.29 ms


## Automatic vectorization by compiler
 + Number of tests: 304
 + FPS: 50.51
 + Milliseconds per frame: $19.798 \pm 0.030$
 + Best  frame: 19.39 ms
 + Worst frame: 21.59 ms


## Intrinsics on 4 threads
 + Number of tests: 1235
 + FPS: 205.72
 + Milliseconds per frame: $4.861 \pm 0.007$
 + Best  frame: 4.68 ms
 + Worst frame: 6.93 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 1
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.378 \pm 0.479$
 + Best  frame: 246.50 ms
 + Worst frame: 259.07 ms


## Intrinsic optimizations
 + Number of tests: 287
 + FPS: 47.69
 + Milliseconds per frame: $20.968 \pm 0.031$
 + Best  frame: 20.57 ms
 + Worst frame: 22.82 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.13
 + Milliseconds per frame: $17.503 \pm 0.024$
 + Best  frame: 17.12 ms
 + Worst frame: 19.20 ms


## Intrinsics on 4 threads
 + Number of tests: 1013
 + FPS: 168.75
 + Milliseconds per frame: $5.926 \pm 0.008$
 + Best  frame: 5.76 ms
 + Worst frame: 7.57 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 2
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 21
 + FPS: 3.49
 + Milliseconds per frame: $286.576 \pm 0.497$
 + Best  frame: 283.70 ms
 + Worst frame: 294.33 ms


## Intrinsic optimizations
 + Number of tests: 349
 + FPS: 58.12
 + Milliseconds per frame: $17.207 \pm 0.027$
 + Best  frame: 16.68 ms
 + Worst frame: 19.05 ms


## Automatic vectorization by compiler
 + Number of tests: 303
 + FPS: 50.47
 + Milliseconds per frame: $19.812 \pm 0.031$
 + Best  frame: 19.37 ms
 + Worst frame: 21.69 ms


## Intrinsics on 4 threads
 + Number of tests: 1326
 + FPS: 220.99
 + Milliseconds per frame: $4.525 \pm 0.006$
 + Best  frame: 4.30 ms
 + Worst frame: 7.27 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 3
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.344 \pm 0.390$
 + Best  frame: 247.18 ms
 + Worst frame: 257.20 ms


## Intrinsic optimizations
 + Number of tests: 443
 + FPS: 73.68
 + Milliseconds per frame: $13.572 \pm 0.021$
 + Best  frame: 13.19 ms
 + Worst frame: 15.60 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.08
 + Milliseconds per frame: $17.520 \pm 0.026$
 + Best  frame: 17.17 ms
 + Worst frame: 19.40 ms


## Intrinsics on 4 threads
 + Number of tests: 1686
 + FPS: 281.06
 + Milliseconds per frame: $3.558 \pm 0.004$
 + Best  frame: 3.41 ms
 + Worst frame: 5.16 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 4
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 22
 + FPS: 3.53
 + Milliseconds per frame: $282.944 \pm 0.323$
 + Best  frame: 281.27 ms
 + Worst frame: 286.76 ms


## Intrinsic optimizations
 + Number of tests: 392
 + FPS: 65.22
 + Milliseconds per frame: $15.332 \pm 0.025$
 + Best  frame: 14.89 ms
 + Worst frame: 17.28 ms


## Automatic vectorization by compiler
 + Number of tests: 303
 + FPS: 50.40
 + Milliseconds per frame: $19.842 \pm 0.030$
 + Best  frame: 19.44 ms
 + Worst frame: 21.82 ms


## Intrinsics on 4 threads
 + Number of tests: 1544
 + FPS: 257.20
 + Milliseconds per frame: $3.888 \pm 0.005$
 + Best  frame: 3.74 ms
 + Worst frame: 5.51 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $253.145 \pm 0.302$
 + Best  frame: 251.53 ms
 + Worst frame: 258.09 ms


## Intrinsic optimizations
 + Number of tests: 442
 + FPS: 73.52
 + Milliseconds per frame: $13.602 \pm 0.021$
 + Best  frame: 13.29 ms
 + Worst frame: 15.30 ms


## Automatic vectorization by compiler
 + Number of tests: 343
 + FPS: 57.05
 + Milliseconds per frame: $17.528 \pm 0.026$
 + Best  frame: 17.17 ms
 + Worst frame: 19.48 ms


## Intrinsics on 4 threads
 + Number of tests: 1663
 + FPS: 277.16
 + Milliseconds per frame: $3.608 \pm 0.004$
 + Best  frame: 3.43 ms
 + Worst frame: 5.28 ms

# Test session
## General information:
```
RESOLUTION: 2304x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 17
 + FPS: 2.82
 + Milliseconds per frame: $354.262 \pm 0.559$
 + Best  frame: 351.35 ms
 + Worst frame: 360.60 ms


## Intrinsic optimizations
 + Number of tests: 312
 + FPS: 51.94
 + Milliseconds per frame: $19.252 \pm 0.031$
 + Best  frame: 18.78 ms
 + Worst frame: 21.11 ms


## Automatic vectorization by compiler
 + Number of tests: 247
 + FPS: 41.10
 + Milliseconds per frame: $24.328 \pm 0.036$
 + Best  frame: 23.84 ms
 + Worst frame: 26.13 ms


## Intrinsics on 4 threads
 + Number of tests: 1167
 + FPS: 194.44
 + Milliseconds per frame: $5.143 \pm 0.007$
 + Best  frame: 4.89 ms
 + Worst frame: 6.76 ms

# Test session
## General information:
```
RESOLUTION: 2688x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 7
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 13
 + FPS: 2.15
 + Milliseconds per frame: $466.079 \pm 0.718$
 + Best  frame: 462.17 ms
 + Worst frame: 472.65 ms


## Intrinsic optimizations
 + Number of tests: 205
 + FPS: 34.14
 + Milliseconds per frame: $29.290 \pm 0.057$
 + Best  frame: 28.32 ms
 + Worst frame: 31.56 ms


## Automatic vectorization by compiler
 + Number of tests: 190
 + FPS: 31.67
 + Milliseconds per frame: $31.579 \pm 0.051$
 + Best  frame: 30.94 ms
 + Worst frame: 33.72 ms


## Intrinsics on 4 threads
 + Number of tests: 776
 + FPS: 129.23
 + Milliseconds per frame: $7.738 \pm 0.010$
 + Best  frame: 7.51 ms
 + Worst frame: 9.29 ms

# Test session
## General information:
```
RESOLUTION: 2048x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 8
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 22
 + FPS: 3.54
 + Milliseconds per frame: $282.686 \pm 0.397$
 + Best  frame: 280.90 ms
 + Worst frame: 289.47 ms


## Intrinsic optimizations
 + Number of tests: 284
 + FPS: 47.29
 + Milliseconds per frame: $21.148 \pm 0.038$
 + Best  frame: 20.43 ms
 + Worst frame: 23.42 ms


## Automatic vectorization by compiler
 + Number of tests: 303
 + FPS: 50.44
 + Milliseconds per frame: $19.824 \pm 0.031$
 + Best  frame: 19.39 ms
 + Worst frame: 21.67 ms


## Intrinsics on 4 threads
 + Number of tests: 1070
 + FPS: 178.25
 + Milliseconds per frame: $5.610 \pm 0.007$
 + Best  frame: 5.35 ms
 + Worst frame: 7.18 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 128
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: double
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.820 \pm 0.333$
 + Best  frame: 251.57 ms
 + Worst frame: 259.59 ms


## Intrinsic optimizations
 + Number of tests: 122
 + FPS: 20.18
 + Milliseconds per frame: $49.550 \pm 0.094$
 + Best  frame: 48.42 ms
 + Worst frame: 51.81 ms


## Automatic vectorization by compiler
 + Number of tests: 226
 + FPS: 37.53
 + Milliseconds per frame: $26.645 \pm 0.040$
 + Best  frame: 26.09 ms
 + Worst frame: 28.52 ms


## Intrinsics on 4 threads
 + Number of tests: 455
 + FPS: 75.71
 + Milliseconds per frame: $13.208 \pm 0.021$
 + Best  frame: 12.75 ms
 + Worst frame: 15.18 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: double
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.00
 + Milliseconds per frame: $249.913 \pm 0.237$
 + Best  frame: 248.67 ms
 + Worst frame: 254.09 ms


## Intrinsic optimizations
 + Number of tests: 235
 + FPS: 39.08
 + Milliseconds per frame: $25.588 \pm 0.040$
 + Best  frame: 25.09 ms
 + Worst frame: 27.48 ms


## Automatic vectorization by compiler
 + Number of tests: 226
 + FPS: 37.60
 + Milliseconds per frame: $26.595 \pm 0.040$
 + Best  frame: 26.08 ms
 + Worst frame: 28.36 ms


## Intrinsics on 4 threads
 + Number of tests: 870
 + FPS: 144.95
 + Milliseconds per frame: $6.899 \pm 0.010$
 + Best  frame: 6.62 ms
 + Worst frame: 8.77 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: double
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.292 \pm 0.458$
 + Best  frame: 250.03 ms
 + Worst frame: 261.21 ms


## Intrinsic optimizations
 + Number of tests: 248
 + FPS: 41.32
 + Milliseconds per frame: $24.199 \pm 0.038$
 + Best  frame: 23.72 ms
 + Worst frame: 26.10 ms


## Automatic vectorization by compiler
 + Number of tests: 226
 + FPS: 37.53
 + Milliseconds per frame: $26.642 \pm 0.041$
 + Best  frame: 26.08 ms
 + Worst frame: 28.89 ms


## Intrinsics on 4 threads
 + Number of tests: 933
 + FPS: 155.42
 + Milliseconds per frame: $6.434 \pm 0.009$
 + Best  frame: 6.17 ms
 + Worst frame: 8.07 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 1
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.553 \pm 0.493$
 + Best  frame: 247.39 ms
 + Worst frame: 257.14 ms


## Intrinsic optimizations
 + Number of tests: 445
 + FPS: 74.04
 + Milliseconds per frame: $13.507 \pm 0.019$
 + Best  frame: 13.22 ms
 + Worst frame: 15.20 ms


## Automatic vectorization by compiler
 + Number of tests: 25
 + FPS: 4.04
 + Milliseconds per frame: $247.344 \pm 0.146$
 + Best  frame: 245.75 ms
 + Worst frame: 249.09 ms


## Intrinsics on 4 threads
 + Number of tests: 1678
 + FPS: 279.64
 + Milliseconds per frame: $3.576 \pm 0.005$
 + Best  frame: 3.39 ms
 + Worst frame: 5.14 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 2
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.755 \pm 0.347$
 + Best  frame: 251.11 ms
 + Worst frame: 257.68 ms


## Intrinsic optimizations
 + Number of tests: 443
 + FPS: 73.69
 + Milliseconds per frame: $13.570 \pm 0.021$
 + Best  frame: 13.25 ms
 + Worst frame: 15.54 ms


## Automatic vectorization by compiler
 + Number of tests: 46
 + FPS: 7.57
 + Milliseconds per frame: $132.153 \pm 0.168$
 + Best  frame: 129.87 ms
 + Worst frame: 134.78 ms


## Intrinsics on 4 threads
 + Number of tests: 1673
 + FPS: 278.86
 + Milliseconds per frame: $3.586 \pm 0.004$
 + Best  frame: 3.43 ms
 + Worst frame: 5.15 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 4
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.496 \pm 0.283$
 + Best  frame: 251.15 ms
 + Worst frame: 257.67 ms


## Intrinsic optimizations
 + Number of tests: 441
 + FPS: 73.36
 + Milliseconds per frame: $13.632 \pm 0.021$
 + Best  frame: 13.29 ms
 + Worst frame: 15.52 ms


## Automatic vectorization by compiler
 + Number of tests: 67
 + FPS: 11.09
 + Milliseconds per frame: $90.210 \pm 0.147$
 + Best  frame: 88.52 ms
 + Worst frame: 92.59 ms


## Intrinsics on 4 threads
 + Number of tests: 1669
 + FPS: 278.09
 + Milliseconds per frame: $3.596 \pm 0.004$
 + Best  frame: 3.43 ms
 + Worst frame: 5.17 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 8
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.97
 + Milliseconds per frame: $252.121 \pm 0.250$
 + Best  frame: 251.08 ms
 + Worst frame: 256.74 ms


## Intrinsic optimizations
 + Number of tests: 445
 + FPS: 74.02
 + Milliseconds per frame: $13.510 \pm 0.019$
 + Best  frame: 13.23 ms
 + Worst frame: 15.16 ms


## Automatic vectorization by compiler
 + Number of tests: 95
 + FPS: 15.67
 + Milliseconds per frame: $63.799 \pm 0.094$
 + Best  frame: 62.62 ms
 + Worst frame: 65.95 ms


## Intrinsics on 4 threads
 + Number of tests: 1675
 + FPS: 279.10
 + Milliseconds per frame: $3.583 \pm 0.005$
 + Best  frame: 3.43 ms
 + Worst frame: 5.32 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 12
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.376 \pm 0.241$
 + Best  frame: 248.09 ms
 + Worst frame: 252.25 ms


## Intrinsic optimizations
 + Number of tests: 444
 + FPS: 73.95
 + Milliseconds per frame: $13.522 \pm 0.019$
 + Best  frame: 13.23 ms
 + Worst frame: 15.27 ms


## Automatic vectorization by compiler
 + Number of tests: 112
 + FPS: 18.52
 + Milliseconds per frame: $54.003 \pm 0.088$
 + Best  frame: 52.86 ms
 + Worst frame: 56.35 ms


## Intrinsics on 4 threads
 + Number of tests: 1674
 + FPS: 279.02
 + Milliseconds per frame: $3.584 \pm 0.004$
 + Best  frame: 3.42 ms
 + Worst frame: 5.18 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 16
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.771 \pm 0.289$
 + Best  frame: 251.42 ms
 + Worst frame: 257.79 ms


## Intrinsic optimizations
 + Number of tests: 439
 + FPS: 73.15
 + Milliseconds per frame: $13.670 \pm 0.022$
 + Best  frame: 13.30 ms
 + Worst frame: 15.56 ms


## Automatic vectorization by compiler
 + Number of tests: 184
 + FPS: 30.59
 + Milliseconds per frame: $32.686 \pm 0.056$
 + Best  frame: 32.01 ms
 + Worst frame: 34.68 ms


## Intrinsics on 4 threads
 + Number of tests: 1665
 + FPS: 277.55
 + Milliseconds per frame: $3.603 \pm 0.005$
 + Best  frame: 3.43 ms
 + Worst frame: 5.20 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 24
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.584 \pm 0.449$
 + Best  frame: 244.86 ms
 + Worst frame: 257.22 ms


## Intrinsic optimizations
 + Number of tests: 440
 + FPS: 73.23
 + Milliseconds per frame: $13.655 \pm 0.023$
 + Best  frame: 13.26 ms
 + Worst frame: 16.47 ms


## Automatic vectorization by compiler
 + Number of tests: 331
 + FPS: 55.04
 + Milliseconds per frame: $18.168 \pm 0.026$
 + Best  frame: 17.81 ms
 + Worst frame: 19.86 ms


## Intrinsics on 4 threads
 + Number of tests: 1669
 + FPS: 278.16
 + Milliseconds per frame: $3.595 \pm 0.004$
 + Best  frame: 3.41 ms
 + Worst frame: 5.21 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 32
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.670 \pm 0.456$
 + Best  frame: 250.25 ms
 + Worst frame: 261.57 ms


## Intrinsic optimizations
 + Number of tests: 444
 + FPS: 73.86
 + Milliseconds per frame: $13.539 \pm 0.020$
 + Best  frame: 13.25 ms
 + Worst frame: 15.27 ms


## Automatic vectorization by compiler
 + Number of tests: 342
 + FPS: 56.88
 + Milliseconds per frame: $17.581 \pm 0.027$
 + Best  frame: 17.17 ms
 + Worst frame: 19.80 ms


## Intrinsics on 4 threads
 + Number of tests: 1658
 + FPS: 276.32
 + Milliseconds per frame: $3.619 \pm 0.004$
 + Best  frame: 3.45 ms
 + Worst frame: 5.23 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 40
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.599 \pm 0.334$
 + Best  frame: 245.96 ms
 + Worst frame: 255.12 ms


## Intrinsic optimizations
 + Number of tests: 442
 + FPS: 73.55
 + Milliseconds per frame: $13.596 \pm 0.022$
 + Best  frame: 13.28 ms
 + Worst frame: 15.62 ms


## Automatic vectorization by compiler
 + Number of tests: 369
 + FPS: 61.39
 + Milliseconds per frame: $16.288 \pm 0.023$
 + Best  frame: 15.95 ms
 + Worst frame: 17.97 ms


## Intrinsics on 4 threads
 + Number of tests: 1670
 + FPS: 278.24
 + Milliseconds per frame: $3.594 \pm 0.004$
 + Best  frame: 3.43 ms
 + Worst frame: 5.17 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 48
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.167 \pm 0.408$
 + Best  frame: 245.11 ms
 + Worst frame: 256.82 ms


## Intrinsic optimizations
 + Number of tests: 444
 + FPS: 73.88
 + Milliseconds per frame: $13.536 \pm 0.019$
 + Best  frame: 13.26 ms
 + Worst frame: 15.28 ms


## Automatic vectorization by compiler
 + Number of tests: 392
 + FPS: 65.27
 + Milliseconds per frame: $15.321 \pm 0.022$
 + Best  frame: 14.98 ms
 + Worst frame: 17.03 ms


## Intrinsics on 4 threads
 + Number of tests: 1665
 + FPS: 277.47
 + Milliseconds per frame: $3.604 \pm 0.004$
 + Best  frame: 3.42 ms
 + Worst frame: 5.15 ms

# Test session
## General information:
```
RESOLUTION: 4480x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 56
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 7
 + FPS: 1.03
 + Milliseconds per frame: $973.135 \pm 1.414$
 + Best  frame: 970.26 ms
 + Worst frame: 981.27 ms


## Intrinsic optimizations
 + Number of tests: 133
 + FPS: 21.99
 + Milliseconds per frame: $45.467 \pm 0.076$
 + Best  frame: 44.54 ms
 + Worst frame: 47.66 ms


## Automatic vectorization by compiler
 + Number of tests: 112
 + FPS: 18.66
 + Milliseconds per frame: $53.589 \pm 0.087$
 + Best  frame: 52.47 ms
 + Worst frame: 55.82 ms


## Intrinsics on 4 threads
 + Number of tests: 498
 + FPS: 82.82
 + Milliseconds per frame: $12.074 \pm 0.018$
 + Best  frame: 11.67 ms
 + Worst frame: 13.90 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.502 \pm 0.355$
 + Best  frame: 251.00 ms
 + Worst frame: 258.46 ms


## Intrinsic optimizations
 + Number of tests: 444
 + FPS: 73.86
 + Milliseconds per frame: $13.540 \pm 0.020$
 + Best  frame: 13.26 ms
 + Worst frame: 15.29 ms


## Automatic vectorization by compiler
 + Number of tests: 404
 + FPS: 67.29
 + Milliseconds per frame: $14.860 \pm 0.022$
 + Best  frame: 14.51 ms
 + Worst frame: 16.63 ms


## Intrinsics on 4 threads
 + Number of tests: 1670
 + FPS: 278.24
 + Milliseconds per frame: $3.594 \pm 0.004$
 + Best  frame: 3.43 ms
 + Worst frame: 5.14 ms

# Test session
## General information:
```
RESOLUTION: 5760x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 72
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 5
 + FPS: 0.75
 + Milliseconds per frame: $1336.333 \pm 3.930$
 + Best  frame: 1330.92 ms
 + Worst frame: 1351.83 ms


## Intrinsic optimizations
 + Number of tests: 98
 + FPS: 16.24
 + Milliseconds per frame: $61.575 \pm 0.115$
 + Best  frame: 60.25 ms
 + Worst frame: 64.55 ms


## Automatic vectorization by compiler
 + Number of tests: 84
 + FPS: 13.98
 + Milliseconds per frame: $71.545 \pm 0.128$
 + Best  frame: 69.72 ms
 + Worst frame: 74.32 ms


## Intrinsics on 4 threads
 + Number of tests: 368
 + FPS: 61.32
 + Milliseconds per frame: $16.308 \pm 0.026$
 + Best  frame: 15.75 ms
 + Worst frame: 19.17 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 80
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.99
 + Milliseconds per frame: $250.353 \pm 0.391$
 + Best  frame: 248.06 ms
 + Worst frame: 257.72 ms


## Intrinsic optimizations
 + Number of tests: 438
 + FPS: 72.96
 + Milliseconds per frame: $13.707 \pm 0.023$
 + Best  frame: 13.30 ms
 + Worst frame: 15.66 ms


## Automatic vectorization by compiler
 + Number of tests: 395
 + FPS: 65.82
 + Milliseconds per frame: $15.193 \pm 0.025$
 + Best  frame: 14.81 ms
 + Worst frame: 17.88 ms


## Intrinsics on 4 threads
 + Number of tests: 1642
 + FPS: 273.60
 + Milliseconds per frame: $3.655 \pm 0.005$
 + Best  frame: 3.50 ms
 + Worst frame: 8.12 ms

# Test session
## General information:
```
RESOLUTION: 7040x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 88
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 4
 + FPS: 0.58
 + Milliseconds per frame: $1720.403 \pm 4.748$
 + Best  frame: 1713.26 ms
 + Worst frame: 1734.17 ms


## Intrinsic optimizations
 + Number of tests: 77
 + FPS: 12.76
 + Milliseconds per frame: $78.361 \pm 0.161$
 + Best  frame: 76.48 ms
 + Worst frame: 80.96 ms


## Automatic vectorization by compiler
 + Number of tests: 66
 + FPS: 10.85
 + Milliseconds per frame: $92.143 \pm 0.186$
 + Best  frame: 89.88 ms
 + Worst frame: 95.16 ms


## Intrinsics on 4 threads
 + Number of tests: 291
 + FPS: 48.34
 + Milliseconds per frame: $20.687 \pm 0.036$
 + Best  frame: 20.08 ms
 + Worst frame: 22.81 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 96
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.342 \pm 0.363$
 + Best  frame: 247.83 ms
 + Worst frame: 256.41 ms


## Intrinsic optimizations
 + Number of tests: 444
 + FPS: 73.85
 + Milliseconds per frame: $13.541 \pm 0.021$
 + Best  frame: 13.23 ms
 + Worst frame: 16.25 ms


## Automatic vectorization by compiler
 + Number of tests: 390
 + FPS: 64.98
 + Milliseconds per frame: $15.390 \pm 0.024$
 + Best  frame: 15.03 ms
 + Worst frame: 17.43 ms


## Intrinsics on 4 threads
 + Number of tests: 1665
 + FPS: 277.39
 + Milliseconds per frame: $3.605 \pm 0.005$
 + Best  frame: 3.42 ms
 + Worst frame: 5.23 ms

# Test session
## General information:
```
RESOLUTION: 8320x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 104
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 3
 + FPS: 0.48
 + Milliseconds per frame: $2077.837 \pm 6.032$
 + Best  frame: 2070.31 ms
 + Worst frame: 2089.77 ms


## Intrinsic optimizations
 + Number of tests: 65
 + FPS: 10.68
 + Milliseconds per frame: $93.597 \pm 0.175$
 + Best  frame: 91.50 ms
 + Worst frame: 96.26 ms


## Automatic vectorization by compiler
 + Number of tests: 53
 + FPS: 8.76
 + Milliseconds per frame: $114.165 \pm 0.226$
 + Best  frame: 110.62 ms
 + Worst frame: 117.17 ms


## Intrinsics on 4 threads
 + Number of tests: 243
 + FPS: 40.38
 + Milliseconds per frame: $24.767 \pm 0.041$
 + Best  frame: 24.10 ms
 + Worst frame: 26.94 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 1024
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 7
 + FPS: 1.04
 + Milliseconds per frame: $957.302 \pm 1.269$
 + Best  frame: 954.33 ms
 + Worst frame: 962.28 ms


## Intrinsic optimizations
 + Number of tests: 121
 + FPS: 20.06
 + Milliseconds per frame: $49.857 \pm 0.086$
 + Best  frame: 48.84 ms
 + Worst frame: 51.99 ms


## Automatic vectorization by compiler
 + Number of tests: 110
 + FPS: 18.31
 + Milliseconds per frame: $54.609 \pm 0.085$
 + Best  frame: 53.58 ms
 + Worst frame: 56.65 ms


## Intrinsics on 4 threads
 + Number of tests: 456
 + FPS: 75.93
 + Milliseconds per frame: $13.170 \pm 0.020$
 + Best  frame: 12.78 ms
 + Worst frame: 14.92 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 1024
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 7
 + FPS: 1.04
 + Milliseconds per frame: $957.657 \pm 1.032$
 + Best  frame: 954.06 ms
 + Worst frame: 963.18 ms


## Intrinsic optimizations
 + Number of tests: 120
 + FPS: 19.86
 + Milliseconds per frame: $50.360 \pm 0.100$
 + Best  frame: 48.99 ms
 + Worst frame: 52.81 ms


## Automatic vectorization by compiler
 + Number of tests: 110
 + FPS: 18.27
 + Milliseconds per frame: $54.749 \pm 0.088$
 + Best  frame: 53.70 ms
 + Worst frame: 56.83 ms


## Intrinsics on 4 threads
 + Number of tests: 446
 + FPS: 74.23
 + Milliseconds per frame: $13.471 \pm 0.021$
 + Best  frame: 13.08 ms
 + Worst frame: 15.53 ms

# Test session
## General information:
```
RESOLUTION: 3840x2160
MAX_ITERS: 1024
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 2
 + FPS: 0.26
 + Milliseconds per frame: $3830.785 \pm 12.494$
 + Best  frame: 3818.29 ms
 + Worst frame: 3843.28 ms


## Intrinsic optimizations
 + Number of tests: 32
 + FPS: 5.25
 + Milliseconds per frame: $190.348 \pm 0.101$
 + Best  frame: 188.69 ms
 + Worst frame: 191.85 ms


## Automatic vectorization by compiler
 + Number of tests: 30
 + FPS: 4.90
 + Milliseconds per frame: $204.199 \pm 0.102$
 + Best  frame: 202.11 ms
 + Worst frame: 205.46 ms


## Intrinsics on 4 threads
 + Number of tests: 117
 + FPS: 19.50
 + Milliseconds per frame: $51.293 \pm 0.105$
 + Best  frame: 49.94 ms
 + Worst frame: 54.05 ms

# Test session
## General information:
```
RESOLUTION: 3840x2160
MAX_ITERS: 1024
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 512
MM_PACKS: 5
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 2
 + FPS: 0.26
 + Milliseconds per frame: $3818.457 \pm 8.408$
 + Best  frame: 3810.05 ms
 + Worst frame: 3826.86 ms


## Intrinsic optimizations
 + Number of tests: 33
 + FPS: 5.48
 + Milliseconds per frame: $182.318 \pm 0.153$
 + Best  frame: 179.08 ms
 + Worst frame: 183.75 ms


## Automatic vectorization by compiler
 + Number of tests: 30
 + FPS: 4.91
 + Milliseconds per frame: $203.873 \pm 0.137$
 + Best  frame: 200.18 ms
 + Worst frame: 205.05 ms


## Intrinsics on 4 threads
 + Number of tests: 125
 + FPS: 20.75
 + Milliseconds per frame: $48.203 \pm 0.086$
 + Best  frame: 46.99 ms
 + Worst frame: 50.31 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 1
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $252.932 \pm 0.391$
 + Best  frame: 251.10 ms
 + Worst frame: 258.54 ms


## Intrinsic optimizations
 + Number of tests: 433
 + FPS: 72.08
 + Milliseconds per frame: $13.873 \pm 0.024$
 + Best  frame: 13.35 ms
 + Worst frame: 15.82 ms


## Automatic vectorization by compiler
 + Number of tests: 405
 + FPS: 67.40
 + Milliseconds per frame: $14.836 \pm 0.021$
 + Best  frame: 14.49 ms
 + Worst frame: 16.65 ms


## Intrinsics on 1 threads
 + Number of tests: 424
 + FPS: 70.56
 + Milliseconds per frame: $14.173 \pm 0.022$
 + Best  frame: 13.67 ms
 + Worst frame: 16.58 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 2
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.00
 + Milliseconds per frame: $249.832 \pm 0.388$
 + Best  frame: 248.09 ms
 + Worst frame: 257.12 ms


## Intrinsic optimizations
 + Number of tests: 435
 + FPS: 72.40
 + Milliseconds per frame: $13.812 \pm 0.021$
 + Best  frame: 13.35 ms
 + Worst frame: 15.74 ms


## Automatic vectorization by compiler
 + Number of tests: 403
 + FPS: 67.06
 + Milliseconds per frame: $14.913 \pm 0.021$
 + Best  frame: 14.53 ms
 + Worst frame: 16.76 ms


## Intrinsics on 2 threads
 + Number of tests: 838
 + FPS: 139.55
 + Milliseconds per frame: $7.166 \pm 0.011$
 + Best  frame: 6.88 ms
 + Worst frame: 11.08 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 3
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $253.028 \pm 0.477$
 + Best  frame: 247.77 ms
 + Worst frame: 260.28 ms


## Intrinsic optimizations
 + Number of tests: 433
 + FPS: 72.04
 + Milliseconds per frame: $13.881 \pm 0.022$
 + Best  frame: 13.41 ms
 + Worst frame: 15.80 ms


## Automatic vectorization by compiler
 + Number of tests: 405
 + FPS: 67.44
 + Milliseconds per frame: $14.828 \pm 0.021$
 + Best  frame: 14.46 ms
 + Worst frame: 17.16 ms


## Intrinsics on 3 threads
 + Number of tests: 1232
 + FPS: 205.30
 + Milliseconds per frame: $4.871 \pm 0.006$
 + Best  frame: 4.70 ms
 + Worst frame: 6.55 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $253.313 \pm 0.559$
 + Best  frame: 251.18 ms
 + Worst frame: 263.15 ms


## Intrinsic optimizations
 + Number of tests: 435
 + FPS: 72.46
 + Milliseconds per frame: $13.800 \pm 0.023$
 + Best  frame: 13.34 ms
 + Worst frame: 15.73 ms


## Automatic vectorization by compiler
 + Number of tests: 402
 + FPS: 66.96
 + Milliseconds per frame: $14.935 \pm 0.021$
 + Best  frame: 14.55 ms
 + Worst frame: 16.85 ms


## Intrinsics on 4 threads
 + Number of tests: 1626
 + FPS: 270.93
 + Milliseconds per frame: $3.691 \pm 0.005$
 + Best  frame: 3.54 ms
 + Worst frame: 5.60 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 5
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $252.905 \pm 0.440$
 + Best  frame: 251.08 ms
 + Worst frame: 261.24 ms


## Intrinsic optimizations
 + Number of tests: 435
 + FPS: 72.45
 + Milliseconds per frame: $13.802 \pm 0.024$
 + Best  frame: 13.36 ms
 + Worst frame: 16.58 ms


## Automatic vectorization by compiler
 + Number of tests: 406
 + FPS: 67.65
 + Milliseconds per frame: $14.782 \pm 0.022$
 + Best  frame: 14.45 ms
 + Worst frame: 16.65 ms


## Intrinsics on 5 threads
 + Number of tests: 1991
 + FPS: 331.79
 + Milliseconds per frame: $3.014 \pm 0.004$
 + Best  frame: 2.85 ms
 + Worst frame: 7.76 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 6
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.238 \pm 0.258$
 + Best  frame: 250.54 ms
 + Worst frame: 255.74 ms


## Intrinsic optimizations
 + Number of tests: 440
 + FPS: 73.24
 + Milliseconds per frame: $13.654 \pm 0.021$
 + Best  frame: 13.34 ms
 + Worst frame: 15.46 ms


## Automatic vectorization by compiler
 + Number of tests: 405
 + FPS: 67.34
 + Milliseconds per frame: $14.850 \pm 0.021$
 + Best  frame: 14.51 ms
 + Worst frame: 16.52 ms


## Intrinsics on 6 threads
 + Number of tests: 2316
 + FPS: 385.95
 + Milliseconds per frame: $2.591 \pm 0.003$
 + Best  frame: 2.45 ms
 + Worst frame: 4.83 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 7
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.02
 + Milliseconds per frame: $249.030 \pm 0.279$
 + Best  frame: 247.21 ms
 + Worst frame: 253.77 ms


## Intrinsic optimizations
 + Number of tests: 440
 + FPS: 73.25
 + Milliseconds per frame: $13.651 \pm 0.021$
 + Best  frame: 13.34 ms
 + Worst frame: 15.43 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.76
 + Milliseconds per frame: $14.757 \pm 0.021$
 + Best  frame: 14.44 ms
 + Worst frame: 16.86 ms


## Intrinsics on 7 threads
 + Number of tests: 2619
 + FPS: 436.49
 + Milliseconds per frame: $2.291 \pm 0.003$
 + Best  frame: 2.11 ms
 + Worst frame: 7.40 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 8
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.348 \pm 0.298$
 + Best  frame: 247.99 ms
 + Worst frame: 254.87 ms


## Intrinsic optimizations
 + Number of tests: 438
 + FPS: 72.90
 + Milliseconds per frame: $13.718 \pm 0.023$
 + Best  frame: 13.34 ms
 + Worst frame: 15.65 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.68
 + Milliseconds per frame: $14.776 \pm 0.021$
 + Best  frame: 14.46 ms
 + Worst frame: 16.52 ms


## Intrinsics on 8 threads
 + Number of tests: 2817
 + FPS: 469.70
 + Milliseconds per frame: $2.129 \pm 0.003$
 + Best  frame: 1.90 ms
 + Worst frame: 5.67 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 9
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.304 \pm 0.424$
 + Best  frame: 245.82 ms
 + Worst frame: 255.85 ms


## Intrinsic optimizations
 + Number of tests: 439
 + FPS: 73.12
 + Milliseconds per frame: $13.677 \pm 0.021$
 + Best  frame: 13.34 ms
 + Worst frame: 16.04 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.78
 + Milliseconds per frame: $14.754 \pm 0.021$
 + Best  frame: 14.45 ms
 + Worst frame: 16.43 ms


## Intrinsics on 9 threads
 + Number of tests: 2671
 + FPS: 445.24
 + Milliseconds per frame: $2.246 \pm 0.003$
 + Best  frame: 1.92 ms
 + Worst frame: 7.20 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 10
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.387 \pm 0.248$
 + Best  frame: 248.17 ms
 + Worst frame: 253.59 ms


## Intrinsic optimizations
 + Number of tests: 435
 + FPS: 72.46
 + Milliseconds per frame: $13.800 \pm 0.024$
 + Best  frame: 13.34 ms
 + Worst frame: 15.82 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.72
 + Milliseconds per frame: $14.767 \pm 0.022$
 + Best  frame: 14.43 ms
 + Worst frame: 16.51 ms


## Intrinsics on 10 threads
 + Number of tests: 2868
 + FPS: 478.01
 + Milliseconds per frame: $2.092 \pm 0.002$
 + Best  frame: 1.87 ms
 + Worst frame: 3.74 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 11
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.649 \pm 0.293$
 + Best  frame: 246.67 ms
 + Worst frame: 254.08 ms


## Intrinsic optimizations
 + Number of tests: 433
 + FPS: 72.06
 + Milliseconds per frame: $13.878 \pm 0.025$
 + Best  frame: 13.41 ms
 + Worst frame: 16.22 ms


## Automatic vectorization by compiler
 + Number of tests: 405
 + FPS: 67.46
 + Milliseconds per frame: $14.824 \pm 0.023$
 + Best  frame: 14.52 ms
 + Worst frame: 16.92 ms


## Intrinsics on 11 threads
 + Number of tests: 2874
 + FPS: 479.16
 + Milliseconds per frame: $2.087 \pm 0.003$
 + Best  frame: 1.85 ms
 + Worst frame: 6.01 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 1
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.95
 + Milliseconds per frame: $252.932 \pm 0.465$
 + Best  frame: 248.66 ms
 + Worst frame: 259.93 ms


## Intrinsic optimizations
 + Number of tests: 439
 + FPS: 73.01
 + Milliseconds per frame: $13.696 \pm 0.022$
 + Best  frame: 13.35 ms
 + Worst frame: 15.70 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.74
 + Milliseconds per frame: $14.763 \pm 0.021$
 + Best  frame: 14.44 ms
 + Worst frame: 16.46 ms


## Intrinsics on 1 threads
 + Number of tests: 426
 + FPS: 70.98
 + Milliseconds per frame: $14.088 \pm 0.027$
 + Best  frame: 13.60 ms
 + Worst frame: 19.44 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 12
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 4.01
 + Milliseconds per frame: $249.206 \pm 0.282$
 + Best  frame: 247.92 ms
 + Worst frame: 254.57 ms


## Intrinsic optimizations
 + Number of tests: 440
 + FPS: 73.25
 + Milliseconds per frame: $13.651 \pm 0.021$
 + Best  frame: 13.34 ms
 + Worst frame: 15.42 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.75
 + Milliseconds per frame: $14.761 \pm 0.021$
 + Best  frame: 14.44 ms
 + Worst frame: 16.52 ms


## Intrinsics on 12 threads
 + Number of tests: 2894
 + FPS: 482.39
 + Milliseconds per frame: $2.073 \pm 0.003$
 + Best  frame: 1.89 ms
 + Worst frame: 5.74 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 20
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 24
 + FPS: 3.96
 + Milliseconds per frame: $252.615 \pm 0.426$
 + Best  frame: 247.89 ms
 + Worst frame: 259.88 ms


## Intrinsic optimizations
 + Number of tests: 440
 + FPS: 73.20
 + Milliseconds per frame: $13.662 \pm 0.022$
 + Best  frame: 13.34 ms
 + Worst frame: 15.49 ms


## Automatic vectorization by compiler
 + Number of tests: 407
 + FPS: 67.81
 + Milliseconds per frame: $14.747 \pm 0.021$
 + Best  frame: 14.44 ms
 + Worst frame: 16.54 ms


## Intrinsics on 20 threads
 + Number of tests: 2730
 + FPS: 454.96
 + Milliseconds per frame: $2.198 \pm 0.009$
 + Best  frame: 1.64 ms
 + Worst frame: 7.08 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 20
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 20
 + FPS: 3.96
 + Milliseconds per frame: $252.447 \pm 0.539$
 + Best  frame: 247.58 ms
 + Worst frame: 259.25 ms


## Intrinsic optimizations
 + Number of tests: 366
 + FPS: 73.20
 + Milliseconds per frame: $13.662 \pm 0.021$
 + Best  frame: 13.34 ms
 + Worst frame: 15.44 ms


## Automatic vectorization by compiler
 + Number of tests: 339
 + FPS: 67.65
 + Milliseconds per frame: $14.781 \pm 0.022$
 + Best  frame: 14.44 ms
 + Worst frame: 16.50 ms


## Intrinsics on 20 threads
 + Number of tests: 2288
 + FPS: 457.67
 + Milliseconds per frame: $2.185 \pm 0.009$
 + Best  frame: 1.67 ms
 + Worst frame: 5.73 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O0 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 10
 + FPS: 1.41
 + Milliseconds per frame: $708.780 \pm 1.361$
 + Best  frame: 704.40 ms
 + Worst frame: 717.22 ms


## Intrinsic optimizations
 + Number of tests: 19
 + FPS: 3.69
 + Milliseconds per frame: $270.732 \pm 0.588$
 + Best  frame: 265.14 ms
 + Worst frame: 275.32 ms


## Automatic vectorization by compiler
 + Number of tests: 10
 + FPS: 0.78
 + Milliseconds per frame: $1289.737 \pm 2.411$
 + Best  frame: 1278.13 ms
 + Worst frame: 1296.02 ms


## Intrinsics on 4 threads
 + Number of tests: 70
 + FPS: 13.81
 + Milliseconds per frame: $72.424 \pm 0.030$
 + Best  frame: 72.15 ms
 + Worst frame: 73.42 ms

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
MM_PACKS: 6
Auto vectorization size: 64
Number of threads: 4
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -Og -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 21
 + FPS: 4.02
 + Milliseconds per frame: $248.905 \pm 0.440$
 + Best  frame: 245.73 ms
 + Worst frame: 254.08 ms


## Intrinsic optimizations
 + Number of tests: 48
 + FPS: 9.55
 + Milliseconds per frame: $104.742 \pm 0.220$
 + Best  frame: 101.04 ms
 + Worst frame: 107.62 ms


## Automatic vectorization by compiler
 + Number of tests: 11
 + FPS: 2.03
 + Milliseconds per frame: $493.239 \pm 1.031$
 + Best  frame: 489.78 ms
 + Worst frame: 501.16 ms


## Intrinsics on 4 threads
 + Number of tests: 184
 + FPS: 36.64
 + Milliseconds per frame: $27.291 \pm 0.048$
 + Best  frame: 26.22 ms
 + Worst frame: 29.45 ms
