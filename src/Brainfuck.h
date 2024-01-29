#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <string>

// Brainfuck class for running the interpreter

class Brainfuck
{
    // Data array to store data.
    int data[2048] = {0};
    // Data pointer to move in data array.
    size_t dataPtr = 0;

public:
    // Constructor for Brainfuck class
    Brainfuck(const std::string filePath);
};

#endif