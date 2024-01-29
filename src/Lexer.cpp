#include "Lexer.h"

#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

// Acceptable charecters in brainfuck language.
const std::vector<char> acceptableChars = {'>', '<', '+', '.', ',', '-', '[', ']'};

std::vector<Instruction> Lexer::lex()
{
    // Open the file.
    std::ifstream inputFile(filePath);

    // If something went wrong when opening the file return Error.
    if (!inputFile.is_open())
    {
        throw std::runtime_error("\u001b[1m\u001b[31m[ERROR]\u001b[0m: Failed to open file " + filePath);
    }

    std::vector<char> instructionsChar;
    std::vector<Instruction> instructions;

    // Read every char and store it inside instructions vector.
    char c;
    while (inputFile.get(c))
    {
        if (std::find(acceptableChars.begin(), acceptableChars.end(), c) != acceptableChars.end())
        {
            char current = c;
            int count = 1;

            // Check for consecutive repeated characters
            while (inputFile.get(c) && std::find(acceptableChars.begin(), acceptableChars.end(), c) != acceptableChars.end() && current == c)
            {
                count++;
            }

            instructions.push_back({static_cast<InstructionType>(current), count});

            // We need to "undo" the last get() if it was not part of the repeated characters
            if (c != current)
            {
                inputFile.unget();
            }
        }
    }

    inputFile.close();
    return instructions;
}