//Written by Justin and Sodid
// Original Author: Sean Davis

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
void init_values(Registers* registers, int *memory) {
    registers->regs[esp] = 1000;
    registers->regs[eax] = 0;
    registers->regs[ebp] = 996;
    registers->regs[eip] = 100;
    
    
    memory[1000] = 0;
    
    
    
}

char* fetch_instruction(Registers* registers, Reader* reader) {
    registers->regs[eip] += 4;
    return reader->lines[(registers->regs[eip] - 104)/4].info;
}

void parse_instruction(Registers* registers, Decoder* decoder, char* instruction, int *memory) {
    char *token;
    token = malloc(sizeof(char*)*21);
    token = strtok(instruction, " ,");
    strcpy(decoder->opcode, token);
    decoder->operand1 = NULL;
    decoder->operand2 = NULL;

    
    
    while(token != NULL){
        //printf("%s\n", *token);
        token = strtok(NULL, " ,");
        
        
        if(decoder->operand1 == NULL && token != NULL)
        {
            if (strstr(token, "\n") != NULL) {
                
            }
            decoder->operand1 = address(registers, token, memory);
            printf("%s\n", token);
        }
        else if(decoder->operand2 == NULL && token != NULL) {
            decoder->operand2 = address(registers, token, memory);
            printf("%s\n", token);

        }

    }
    
    /*if (decoder->operand1 == NULL) {
        printf("Operand: %s\n", decoder->opcode);
    }
    else if(decoder->operand2 == NULL) {
        printf("Operand: %s      Operator1: %i\n", decoder->opcode, *decoder->operand1);

    }
    else {
        printf("Operand: %s     Operator1: %i     Operator2: %i\n", decoder->opcode, *decoder->operand1, *decoder->operand2);
    }*/

}

void execute_decoder(Registers *registers, Decoder* decoder, int *memory) {
    
}

void parse_operand(Registers *registers, Decoder* decoder, int *memory){
    
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

int main(int argc, char* argv[])
{
    Registers registers;
    Decoder decoder;
    Reader reader;
    int memory[1001];
    
    
    char* tab_location;
    char* newline_location;
    init_values(&registers, memory);
    

    // This code allows a file to be read and for the data to be passed reader.info's character array
    
    
    

    //TODO: create method to input filename by command line argument
    char *buffer;
    buffer = malloc(sizeof(char*)*255);
    
    //loop reads in all of the contetns of the string include earlier. Each line is loaded sperately into the reader struct as a differnt line
    int instruction_counter = 0;
    
    
    FILE *fp;

    fp = fopen("/Users/Sarv/ECS_040_Program_01/test.txt", "r");
    if (fp == NULL) {
        printf("File fucked up");
        return 0;
    }
    
    
    // Reads the data from the .s file and puts it into the reader stuct, while prettying it up a bit
    while (!(fgets(buffer, 255, fp) == NULL)) {
        if ((strstr(buffer, ".") == NULL) && (strstr(buffer, ":") == NULL)) {
            while((tab_location = strstr(buffer, "\t")) != NULL){
                char* temp;
                temp = tab_location;
                *temp = ' ';
            }
            
            newline_location = strstr(buffer, "\n");
            char* temp;
            temp = newline_location;
            *temp = '\0';
            
            reader.lines[instruction_counter].info = malloc((strlen(buffer) + 1)*sizeof(char));
            
            strcpy(reader.lines[instruction_counter].info, buffer);
            
            reader.lines[instruction_counter].address = 100  + (4 * instruction_counter);
            
            //printf("%s", reader.lines[instruction_counter].info);
            instruction_counter++;
        }
    }
    
    //close the file
    fclose(fp);

    
    for(int i = 0; i < instruction_counter; i++) {
        
        char* instruction;
        instruction = fetch_instruction(&registers, &reader);
        parse_instruction(&registers, &decoder, instruction, memory);
        execute_decoder(&registers, &decoder, memory);
        parse_operand(&registers, &decoder, memory);
        printf("%s     eip: %i  eax:  %i ebp:  %i esp:   %i", reader.lines[i].info, registers.regs[eip], registers.regs[eax], registers.regs[ebp], registers.regs[esp]);
        
    }
    
    
    
    /*
    //DEBUG LOOP FOR CONTENTS OF READER.INFO
    for(int i = 0; i < instruction_counter; i++) {
        printf("%s", reader.lines[i].info);
    }
    printf("\n");
    */
    
    return 0;
}  // main()
