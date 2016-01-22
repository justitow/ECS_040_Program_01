#include "registers.h"
#include "reader.h"
#include "decoder.h"

enum {eax, ebp, esp, eip};
int* address(Registers *registers, char *ptr, int memory[]);

void init_values(Registers* registers, int memory[]);
//void read_file(Reader *reader);

char* fetch_instruction(Registers* registers, Reader* reader);
