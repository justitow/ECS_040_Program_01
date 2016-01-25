//
//  decoder.h
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef decoder_h
#define decoder_h

#include <stdio.h>
#include <string.h>
#include "registers.h"

typedef struct Decoder
{
    char opcode[20];
    int* operand1;
    int* operand2;
} Decoder;


void addl(int* op1, int* op2);
void andl(int *op1, int *op2);
void leave(Registers *registers, int memory[]);
void movl(int *op1, int *op2);
void pushl(int *op1, int memory[], Registers *registers);
void ret(Registers *registers, int memory[]);
void subl(int *op1, int *op2);
void parse_operand(Registers* registers, Decoder* decoder, int* memory);
#endif
