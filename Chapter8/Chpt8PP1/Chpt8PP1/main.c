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
#define ZERO 0
#define BLANK ' '
char input[LINE];
char output[LINE];

void myMain();
void inPut();
void deBlank(char *input, char *output, int loopLength);
char *scanLine(char *dest,int dest_len);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
    inPut();
    deBlank(scanLine(input, LINE),output,(int)strlen(input)+1);
    printf("%s",output);
}

void inPut()
{
    printf("Please enter a string to be deblanked --> ");
}

void deBlank(char *input,char *output, int loopLength ){

    int i=ZERO;
    int j=ZERO;
    
    while (i < loopLength) {
        if (input[i] != BLANK) {
            output[j]= input[i];
            j++;//increment output index by one when true
        }
        i++;//traverse array
    }


}


// Based on Figure 8.15 in Book
char *scanLine(char *dest, int dest_len)
{
	int i, ch;
    
	i = ZERO;
    
	for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
		dest[i++] = ch;
        
	}
    
	dest[i] = '\0';
    
	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}
    
	return dest;
}


