#include "Brainfuck.h"
#include "Lexer.h"

#include <stdexcept>
#include <iostream>

Brainfuck::Brainfuck(const std::string filePath)
{
    Lexer lexer(filePath);
    std::vector<Instruction> instructions;

    // Lex the file and store instructions inside instructions vector;
    try
    {
        instructions = lexer.lex();
    }
    catch (std::runtime_error &err)
    {
        throw err;
    }

    for (size_t i = 0; i < instructions.size(); i++)
    {
        Instruction instruction = instructions[i];
        switch (instruction.type)
        {
        // Increment the data pointer by one (to point to the next cell to the right).
        case InstructionType::R_ARROW:
        {
            dataPtr += instruction.count;
            break;
        }
        // Decrement the data pointer by one (to point to the next cell to the left).
        case InstructionType::L_ARROW:
        {
            dataPtr -= instruction.count;
            break;
        }
        // Increment the byte at the data pointer by one.
        case InstructionType::PLUS:
        {
            data[dataPtr] += instruction.count;
            break;
        }
        // Decrement the byte at the data pointer by one.
        case InstructionType::MINUS:
        {
            data[dataPtr] -= instruction.count;
            break;
        }
        // Output the byte at the data pointer.
        case InstructionType::DOT:
        {
            for (size_t j = 0; j < instruction.count; j++)
            {
                std::cout << static_cast<char>(data[dataPtr]) << std::flush;
            }
            break;
        }
        // Accept one byte of input, storing its value in the byte at the data pointer.
        case InstructionType::COMMA:
        {
            std::cin >> data[dataPtr];
            break;
        }
        /*
          If the byte at the data pointer is zero,
          then instead of moving the instruction pointer forward to the next command,
          jump it forward to the command after the matching ] command.
        */
        case InstructionType::L_BRACK:
        {
            if (data[dataPtr] == 0)
            {
                int count = 0;
                for (size_t j = i + 1; j < instructions.size(); j++)
                {
                    if (instructions[j].type == InstructionType::L_BRACK)
                    {
                        count++;
                    }
                    else if (instructions[j].type == InstructionType::R_BRACK)
                    {
                        if (count == 0)
                        {
                            i = j;
                            break;
                        }
                        count--;
                    }
                }
            }
            break;
        }
        /*
          If the byte at the data pointer is nonzero,
          then instead of moving the instruction pointer forward to the next command,
          jump it back to the command after the matching [ command.
        */
        case InstructionType::R_BRACK:
        {
            if (data[dataPtr] != 0)
            {
                int count = 0;
                for (size_t j = i - 1; j > 0; j--)
                {
                    if (instructions[j].type == InstructionType::R_BRACK)
                    {
                        count++;
                    }
                    else if (instructions[j].type == InstructionType::L_BRACK)
                    {
                        if (count == 0)
                        {
                            i = j;
                            break;
                        }
                        count--;
                    }
                }
            }
        }
        }
    }
}