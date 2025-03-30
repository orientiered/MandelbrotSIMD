
# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
Auto vectorization size: 32
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -msse4.1 -msse4.2 -mavx2 -mavx -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 3.04
 + Milliseconds per frame: $328.656 \pm 0.683$
 + Best  time: 323.09
 + Worst time: 337.46


## Intrinsic optimizations
 + Number of tests: 25
 + FPS: 21.92
 + Milliseconds per frame: $45.619 \pm 0.177$
 + Best  time: 44.52
 + Worst time: 47.90


## Automatic vectorization by compiler
 + Number of tests: 25
 + FPS: 28.99
 + Milliseconds per frame: $34.491 \pm 0.231$
 + Best  time: 33.21
 + Worst time: 38.16

# Test session
## General information:
```
RESOLUTION: 1920x1080
MAX_ITERS: 256
PLANE_WIDTH: 3.50000
CENTER: -0.500, 0.000
MM_SIZE: 256
Auto vectorization size: 32
FLOAT TYPE: float
COMPILER: g++
COMPILE FLAGS: -O3 -DNDEBUG -std=c++17 -fopt-info-vec -march=native -I./include
```


## No optimizations
 + Number of tests: 25
 + FPS: 3.04
 + Milliseconds per frame: $329.268 \pm 3.445$
 + Best  time: 322.39
 + Worst time: 410.69


## Intrinsic optimizations
 + Number of tests: 25
 + FPS: 21.71
 + Milliseconds per frame: $46.066 \pm 0.274$
 + Best  time: 44.77
 + Worst time: 51.12


## Automatic vectorization by compiler
 + Number of tests: 25
 + FPS: 28.41
 + Milliseconds per frame: $35.193 \pm 0.272$
 + Best  time: 33.31
 + Worst time: 38.84
