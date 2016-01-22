//
//  decoder.c
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include "decoder.h"
#include "registers.h"
#include "main.h"
#include <stdlib.h>

void addl(int* op1, int* op2){
    *op2 = *op1 + *op2;
}

void andl(int *op1, int *op2){
    
    
    *op2 = *op1 & *op2;
}

void leave(Registers *registers, int *memory){
    
    registers->regs[esp] = registers->regs[ebp];
    registers->regs[esp] = memory[registers->regs[ebp]]+4;
    
}


void movl(int *op1, int *op2){
    
    *op2 = *op1;
    
    
}



void pushl(int *op1, int *memory, Registers *registers){
    
    registers->regs[esp] -= 4;
    memory[registers->regs[esp]] = *op1;
    
    
}


void ret(Registers *registers, int *memory){
    memory[registers->regs[eip]] = memory[registers->regs[esp]];
    registers->regs[esp] += 4;
}


void subl(int *op1, int *op2){
    
    
    *op2 = *op1 - *op2;
    
    
}
