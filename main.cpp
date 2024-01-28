// Brainfuck interpreter written by Hakan Vardar

#include "Lexer.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <stdexcept>

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <script>" << std::endl;
        return 1;
    }

    Lexer lexer(argv[1]);
    auto instructions = lexer.lex();

    for (auto instruction : instructions)
    {
        std::cout << static_cast<char>(instruction.type) << " " << instruction.count << std::endl;
    }

    return 0;
}