#include "Lexer.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <iostream>

std::vector<Instruction> Lexer::lex()
{
    auto filePath = std::filesystem::path(std::filesystem::current_path() / this->filePath);
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        throw std::runtime_error("[ERROR]: Error happened when trying to open the file");
    }

    std::vector<Instruction> instructions = {};
    int count = 1;
    char c, current = '\0';
    while (inputFile.get(c))
    {
        if (current != '\0')
        {
            if (c == current)
            {
                count += 1;
            }
            else
            {
                instructions.push_back({current, count});
                count = 1;
            }
        }
        current = c;
    }

    return instructions;
}