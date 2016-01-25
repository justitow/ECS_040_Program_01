//
//  decoder.c
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "decoder.h"
#include <stdlib.h>

void addl(int* op1, int* op2)
{
    *op2 = *op1 + *op2;
} // addl ()

void andl(int *op1, int *op2)
{
    *op2 = *op1 & *op2;
} //andl ()

void leave(Registers *registers, int memory[])
{
    enum {eax, ebp, esp, eip};
    registers->regs[esp] = registers->regs[ebp];
    registers->regs[esp] = memory[registers->regs[ebp]] + 4;
} //leave ()


void movl(int *op1, int *op2)
{
    *op2 = *op1;
} //movl ()



void pushl(int *op1, int memory[], Registers *registers)
{
    enum {eax, ebp, esp, eip};
    registers->regs[esp] -= 4;
    memory[registers->regs[esp]] = *op1;
} //pushl ()


void ret(Registers *registers, int memory[])
{
    enum {eax, ebp, esp, eip};
    registers->regs[eip] = memory[registers->regs[esp]];
    registers->regs[esp] += 4;
} //ret ()


void subl(int *op1, int *op2)
{
    *op2 = *op2 - *op1;
} //subl ()

void parse_operand(Registers* registers, Decoder* decoder, int *memory)
{

    if(!(strcmp(decoder->opcode, "addl"))) //opcode is addl
        addl(decoder->operand1, decoder->operand2);

    if (!(strcmp(decoder->opcode, "andl"))) //opcode is andl
        andl(decoder->operand1, decoder->operand2);

    if(!(strcmp(decoder->opcode, "leave"))) //opcode is leave
        leave(registers, memory);

    if(!(strcmp(decoder->opcode, "movl"))) //opcode is movl
        movl(decoder->operand1, decoder->operand2);

    if(!(strcmp(decoder->opcode, "pushl"))) //opcode is pushl
        pushl(decoder->operand1, memory, registers);

    if(!(strcmp(decoder->opcode, "ret"))) //opcode is ret
        ret(registers, memory);

    if(!(strcmp(decoder->opcode, "subl"))) //opcode is subl
        subl(decoder->operand1, decoder->operand2);
} //parse_operand ()

