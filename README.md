# BM

![birch](./assets/birch-296x328.png)

Simple Virtual Machine with its own Bytecode and Assembly language.

## Quick Start

```console
$ ./build.sh                  # or ./build_msvc.bat if you are on Windows
$ ./bme -i ./examples/hello.bm
$ ./bme -i ./examples/fib.bm
$ ./bme -i ./examples/e.bm
$ ./bme -i ./examples/pi.bm
```

## Components

### basm

Assembly language for the Virtual Machine. For examples see [./examples/](./examples) folder.

### bme

BM emulator. Used to run programs generated by [basm](#basm).

### debasm

Disassembler for the binary files generated by [basm](#basm)
