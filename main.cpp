// Brainfuck interpreter written by Hakan Vardar
// GitHub: https://github.com/hakanvardar
// Date: 29/01/2024

#include "Brainfuck.h"

#include <iostream>

int main(int argc, char **argv)
{

    // Handle args
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <script>" << std::endl;
        return 1;
    }

    // Run brainfuck interpreter
    try
    {
        Brainfuck brainfuck(argv[1]);
    }
    catch (std::runtime_error &err)
    {
        std::cout << err.what() << std::endl;
        return 1;
    }

    return 0;
}