//
//  main.c
//  deBlankExample
//
//  Created by Randy McMillan on 11/4/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int MAX_LEN = 1000;

void deblank(char* buff, char* result){
    int i=0, j=0;
    int len = (int)strlen(buff)+1;
    
    while (i != len) {
        if (*(buff+i) != ' '){
            *(result+j) = *(buff+i);
            j++;
        }
        i++;
    }
    
    
}

int main()
{
    char *input, *output;
    input = malloc(sizeof(char)*MAX_LEN);
    output = malloc(sizeof(char)*MAX_LEN);
    printf("Please enter a string\n");
    gets(input);
    
    deblank(input, output);
    printf("%s\n", output);
    free(output);
    free(input);
    
    return 0;
}
