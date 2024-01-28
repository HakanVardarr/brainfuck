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
};

class Lexer
{
    const char *filePath;

public:
    Lexer(const char *filePath) : filePath(filePath){};
    std::vector<Instruction> lex();
};

#endif