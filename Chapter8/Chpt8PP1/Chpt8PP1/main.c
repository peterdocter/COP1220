//
//  main.c
//  Chpt8PP1
//
//  Created by Randy McMillan on 11/3/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   1. Write and test a function deblank that takes a string output and a string input argument and returns a copy of the input argument with all blanks removed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 80
#define BLANK ' '
char input[LINE];
char output[LINE];

void myMain();
void inPut();
void deBlank(char *input, char *output, int loopLength);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
    inPut();
    deBlank(input,output,(int)strlen(input));
}

void inPut()
{
    printf("Please enter a string to be deblanked --> ");
    gets(input);
}

void deBlank(char *input,char *output, int loopLength ){


    
    for (int i =0; i<=loopLength;i++) {
        //
        
        if (input[i]!= BLANK) {
            //
            
            
            
        }
        
    }
    


}
