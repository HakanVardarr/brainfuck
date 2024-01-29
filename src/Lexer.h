#ifndef BRAINFUCK_LEXER_H
#define BRAINFUCK_LEXER_H

#include <vector>
#include <string>

// Instruction type for Instruction struct

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

// Instruction class for lexing. Type field refers to InstructionType for parsing. Count field refers to how many times lexer found the same type back to back.

struct Instruction
{
    InstructionType type;
    int count;
};

// Lexer class accepts filePath and lexes the files content.

class Lexer
{
    const std::string filePath;

public:
    // Constructor for lexer

    Lexer(const std::string filePath) : filePath(filePath){};

    // lex the file

    std::vector<Instruction> lex();
};

#endif