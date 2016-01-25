//
//  reader.h
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef reader_h
#define reader_h


#include <stdio.h>
#include "instruction.h"
#include "registers.h"


typedef struct Reader
{
    Instruction lines[1000];
} Reader;

void read_lines(Reader* reader, char* argv);
void tab_to_ws(char* buffer);
void newline_to_null(char* buffer);

#endif 
