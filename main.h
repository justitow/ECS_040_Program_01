#include "registers.h"
#include "reader.h"
#include "decoder.h"

enum {eax, ebp, esp, eip};
int* address(Registers *registers, char *ptr, int memory[]);

void init_values(Registers* registers, int *memory);
//void read_file(Reader *reader);

char* fetch_instruction(Registers* registers, Reader* reader);
void parse_instruction(Registers* registers, Decoder* decoder, char* instruction, int* memory);
void execute_decoder(Registers *registers, Decoder* decoder, int *memory);
