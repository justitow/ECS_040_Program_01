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

void leave(Registers *registers, int memory[]){
    
    registers->regs[esp] = registers->regs[ebp];
    registers->regs[esp] = memory[registers->regs[ebp]]+4;
    
}


void movl(int *op1, int *op2){
    
    *op2 = *op1;
    
    
}



void pushl(int *op1, int memory[], Registers *registers){
    
    registers->regs[esp] -= 4;
    memory[registers->regs[esp]] = *op1;
    
    
}


void ret(Registers *registers, int memory[]){
    //printf("%i %i\n", registers->regs[esp], memory[1000]);
    registers->regs[eip] = memory[registers->regs[esp]];
    //printf("%i %i\n", memory[registers->regs[esp]], registers->regs[eip]);
    registers->regs[esp] += 4;
}


void subl(int *op1, int *op2){
    *op2 = *op2 - *op1;
}

void parse_operand(Registers *registers, Decoder* decoder, int memory[]){
    
    if(!(strcmp(decoder->opcode, "addl"))){
        addl(decoder->operand1, decoder->operand2);
    }
    
    else if (!(strcmp(decoder->opcode, "andl"))){
        andl(decoder->operand1, decoder->operand2);
    }
    
    else if(!(strcmp(decoder->opcode, "leave"))){
        leave(registers, memory);
    }
    
    else if(!(strcmp(decoder->opcode, "movl"))){
        movl(decoder->operand1, decoder->operand2);
    }
    
    else if(!(strcmp(decoder->opcode, "pushl"))){
        pushl(decoder->operand1, memory, registers);
    }
    
    else if(!(strcmp(decoder->opcode, "ret"))){
        ret(registers, memory);
    }
    
    else if(!(strcmp(decoder->opcode, "subl"))){
        subl(decoder->operand1, decoder->operand2);
    }
    
    else{
        fprintf(stderr, "An error occured: %s\n", decoder->opcode);
    }
}


void parse_instruction(Registers* registers, Decoder* decoder, char* instruction, int memory[]) {
    char *token;
    token = malloc(sizeof(char*)*21);
    decoder->operand1 = NULL;
    decoder->operand2 = NULL;
    
    token = strtok(instruction, " ,");
    strcpy(decoder->opcode, token);
    
    printf("%s  ", token);
    while(token != NULL){
        token = strtok(NULL, " ,");
        if(decoder->operand1 == NULL && token != NULL)
        {
            printf("%s", token);
            decoder->operand1 = address(registers, token, memory);
        }
        else if(decoder->operand2 == NULL && token != NULL) {
            printf(", %s     ", token);
            decoder->operand2 = address(registers, token, memory);
        }
    }
}