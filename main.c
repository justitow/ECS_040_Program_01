

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>

//address() written by Sean Davis
int* address(Registers *registers, char *operand, int memory[])
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$') // immediate mode
    {
        value = atoi(&operand[1]);
        return &value;
    } // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
    
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0';  // terminate operand string at first '('
        index = atoi(operand);  // will return 0 if no number there!
        return  &memory[registers->regs[regNum] + index];
    } // if ptr
    else  // direct addressing
        return &(registers->regs[regNum]);
    
} // address ()

//intialize the values of the registers to a new CPU
void init_values(Registers* registers, int memory[])
{
    registers->regs[esp] = 1000;
    registers->regs[eax] = 0;
    registers->regs[ebp] = 996;
    registers->regs[eip] = 100;
    
    
    memory[1000] = 0;
} // init_values ()


void parse(Registers* registers, Decoder* decoder, char* line, int memory[])
{
    char *token, *output, *op1, *op2;
    op1 = NULL;
    op2 = NULL;
    token =(char*)malloc(sizeof(char*)*21);
    output = (char*)malloc(sizeof(char*)*21);
    op1 = (char*)malloc(sizeof(char*)*10);
    decoder->operand1 = NULL;
    decoder->operand2 = NULL;
    token = strtok(line, " ,");
    strcpy(decoder->opcode, token);
    strcpy(output, token);
    
    while(token != NULL)
    {
        token = strtok(NULL, " ,");
        
        if(decoder->operand1 == NULL && token != NULL)
        {
            strcpy(op1, token);
            decoder->operand1 = address(registers, token, memory);
        } //if ()
        
        else //there could be a second operand
        {
            
            if(decoder->operand2 == NULL && token != NULL)
            {
                op2 = (char*)malloc(sizeof(char*)*10);
                strcpy(op2, token);
                decoder->operand2 = address(registers, token, memory);
            } // if()
        } // else()
    } // while()
    
    strcat(output, " ");
    strcat(output, op1);
    
    if(op2 != NULL)
    {
        strcat(output, ", ");
        strcat(output, op2);
    }
    printf("%*s", -20, output);
} //parse_instruction ()


char* fetch_instruction(Registers* registers, Reader* reader)
{
    registers->regs[eip] += 4;
    return reader->lines[(registers->regs[eip] - 104) / 4].info;
} //fetch_instruction ()

int main(int argc, char* argv[])
{
    Registers registers;
    Decoder decoder;
    Reader reader;
    int memory[1001];
    
    init_values(&registers, memory);
    read_lines(&reader, argv[1]);
    
    while(registers.regs[eip] != 0)
    {
        char* line;
        line = fetch_instruction(&registers, &reader);
        parse(&registers, &decoder, line, memory);
        parse_operand(&registers, &decoder, memory);
        printf(" eip: %*i eax: %*i", 3, registers.regs[eip], 3, registers.regs[eax]);
        printf(" ebp: %*i esp: %i\n", 3, registers.regs[ebp], registers.regs[esp]);
    } // while ()
    
    return 0;
}  // main()
