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

    // Read every char and store it inside instructionsChar vector.
    char c;
    while (inputFile.get(c))
    {
        if (std::find(acceptableChars.begin(), acceptableChars.end(), c) != acceptableChars.end())
        {
            instructionsChar.push_back(c);
        }
    }

    // Read ever char that stored in instructionsChar and add the Instruction to the instructions vector.
    for (size_t i = 0; i < instructionsChar.size(); i++)
    {
        char current = instructionsChar[i];
        int count = 1;
        for (size_t j = 1; j + i < instructionsChar.size() && current == instructionsChar[i + j]; j++)
        {
            count++;
        }
        instructions.push_back({static_cast<InstructionType>(current), count});
        i += count - 1;
    }

    inputFile.close();
    return instructions;
}