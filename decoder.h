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

typedef struct Decoder {
    char opcode[20];
    int* operand1;
    int* operand2;
} Decoder;


#endif /* decoder_h */
