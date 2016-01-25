//
//  reader.c
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//


#include "reader.h"
#include <stdlib.h>
#include <string.h>

void read_lines(Reader *reader, char* argv)
{
    char *buffer;
    buffer = (char*)malloc(sizeof(char*) * 255);
    FILE *fp;
    int ic = 0;
    fp = fopen(argv, "r");

    if (fp == NULL)
    {
        printf("Big errors \n");
    } // if
    
    while (!(fgets(buffer, 255, fp) == NULL))
    {
	
        if ((strstr(buffer, ".") == NULL) && (strstr(buffer, ":") == NULL))
        {
            tab_to_ws(buffer);
            newline_to_null(buffer);
            reader->lines[ic].info = (char*)malloc((strlen(buffer) + 1)*sizeof(char));
            strcpy(reader->lines[ic].info, buffer);
            reader->lines[ic].address = 100  + (4 * ic);
            ic++;
        } // if ()

    } // while ()

    fclose(fp);
} //read_lines()

void tab_to_ws(char* buffer)
{

    char* tab;
    
    while((tab = strstr(buffer, "\t")) != NULL)
    {
        char* temp;
        temp = tab;
        *temp = ' ';
    } // while()

} //remove_tab()

void newline_to_null(char* buffer)
{
    char* nl;
    nl = strstr(buffer, "\n");
    char* temp;
    temp = nl;
    *temp = '\0';
} //newling_to_null
