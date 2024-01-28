#include "Lexer.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <algorithm>

const std::vector<char> acceptableChars = {'>', '<', '+', '.', ',', '-', '[', ']'};

std::vector<Instruction> Lexer::lex()
{
    auto filePath = std::filesystem::path(std::filesystem::current_path() / this->filePath);
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        throw std::runtime_error("\u001b[1m\u001b[31m[ERROR]\u001b[0m: Failed to open file" + filePath.string());
    }

    std::vector<Instruction> instructions = {};
    int count = 1;
    char c, current = '\0';
    while (inputFile.get(c))
    {
        if (current != '\0')
        {
            if (current != '\0' && c == current)
            {
                count += 1;
            }
            else
            {
                if (std::find(acceptableChars.begin(), acceptableChars.end(), current) == acceptableChars.end())
                {
                    throw std::runtime_error("\u001b[1m\u001b[31m[ERROR]\u001b[0m: Unkown instruction '" + std::string(1, current) + "'");
                }

                instructions.push_back({(InstructionType)current, count});
                count = 1;
            }
        }
        current = c;
    }

    return instructions;
}