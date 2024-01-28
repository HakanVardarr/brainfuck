#ifndef BRAINFUCK_LEXER_H
#define BRAINFUCK_LEXER_H

#include <vector>

enum InstructionType
{
    R_ARROW = '>',
    L_ARROW = '<',
    PLUS = '+',
    MINUS = '-',
    DOT = '.',
    COMMA = ',',
    R_BRACK = ']',
    L_BRACK = '[',
};

struct Instruction
{
    InstructionType type;
    int count;
    Instruction() = default;
    Instruction(char c, int count) : count(count)
    {
        switch (c)
        {
        case '>':
        {
            type = InstructionType::R_ARROW;
            break;
        }
        case '<':
        {
            type = InstructionType::L_ARROW;
            break;
        }
        case '+':
        {
            type = InstructionType::PLUS;
            break;
        }
        case '-':
        {
            type = InstructionType::MINUS;
            break;
        }
        case '.':
        {
            type = InstructionType::DOT;
            break;
        }
        case ',':
        {
            type = InstructionType::COMMA;
            break;
        }
        case '[':
        {
            type = InstructionType::L_BRACK;
            break;
        }
        case ']':
        {
            type = InstructionType::R_BRACK;
            break;
        }
        default:
            break;
        }
    };
};

class Lexer
{
    char *filePath;

public:
    Lexer(char *filePath) : filePath(filePath){};
    std::vector<Instruction> lex();
};

#endif