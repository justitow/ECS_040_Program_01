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

void read_lines(Reader *reader)
{
    char* tab_location;
    char* newline_location;
    char *buffer;
    buffer = malloc(sizeof(char*) * 255);
    FILE *fp;
    int instruction_counter = 0;
    
<<<<<<< HEAD
    fp = fopen("/Users/Sarv/ECS_040_Program_01/test.txt", "r");
    if (fp == NULL) {
=======
    fp = fopen("/Users/justin/Developer/ECS_040_Project_01/ECS_040_Program_01/test.txt", "r");

    if (fp == NULL)
    {
>>>>>>> ac79ab098f20b46326c8beb96f35178c4c660631
        printf("File fucked up\n");
    } // if
    
    while (!(fgets(buffer, 255, fp) == NULL))
    {

        if ((strstr(buffer, ".") == NULL) && (strstr(buffer, ":") == NULL))
        {

            while((tab_location = strstr(buffer, "\t")) != NULL){
                char* temp;
                temp = tab_location;
                *temp = ' ';
            } // while()
            newline_location = strstr(buffer, "\n");
            char* temp;
            temp = newline_location;
            *temp = '\0';
            reader->lines[instruction_counter].info = malloc((strlen(buffer) + 1)*sizeof(char));
            strcpy(reader->lines[instruction_counter].info, buffer);
            reader->lines[instruction_counter].address = 100  + (4 * instruction_counter);
            instruction_counter++;
        } // if ()
    } // while ()
    fclose(fp);
}