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
#include "reader.h"

typedef struct Reader
{
    Instruction lines[1000];
} Reader;

void read_lines(Reader* reader, char* argv);

#endif // reader_h 
