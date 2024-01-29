# Brainfuck Interpreter

## Overview
This is a simple Brainfuck interpreter written in C++. Brainfuck is an esoteric programming language known for its minimalistic design. The interpreter reads Brainfuck code from a file and executes the instructions accordingly.

## Geting Started

### Prerequisites
- C++ compiler (supporting c++ 11 or later)
- [CMake](https://cmake.org/) (For building the project)

### Building 

```bash
git clone https://github.com/HakanVardarr/brainfuck.git
cd brainfuck
mkdir build
cd build
cmake ..
```
This will generate makefile on your build folder or if you are in windows that will genearte brainfuck.sln.
- Windows: 
```bash
MSBuild.exe .\brainfuck.sln   
```
- MacOS / Linux:
```bash
make
```

## Usage
```bash
./brainfuck <script.bf>
```

## Example
```bash
./brainfuck examples/hello_World.bf
```

## Credits

This Brainfuck interpreter is inspired by and follows the specification provided by the [Brainfuck programming language](https://en.wikipedia.org/wiki/Brainfuck) on Wikipedia.

The Brainfuck language was created by Urban Müller in 1993. For more information about Brainfuck and its history, please refer to the Wikipedia page: [Brainfuck - Wikipedia](https://en.wikipedia.org/wiki/Brainfuck).
