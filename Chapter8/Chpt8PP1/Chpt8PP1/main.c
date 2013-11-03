//
//  main.c
//  Chpt8PP1
//
//  Created by Randy McMillan on 11/3/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//


/*

 1. Write and test a function deblank that takes a string output and a string input argument and returns a copy of the input argument with all blanks removed.
 
*/

#include <stdio.h>
#define LINE 80

void myMain();

void input();

char beBlank(char input);

char line[LINE];

char *scanline(char *dest,int dest_len);

int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}

void myMain(){

    input();

}



void input(){

    printf("Please enter a line of text --> ");
    printf("%s",scanline(line, LINE));
    
}


char *scanline(char *dest,int dest_len){

    int i,ch;
    i=0;
    for (ch = getchar(); ch !='\n' && ch != EOF && i < dest_len -1; ch = getchar()) {
        dest[i++] = ch;
        
    }
    dest[i]='\0';
    
    /* Discards any characters that remain on input line */ while (ch != '\n' && ch != EOF)
        ch = getchar();
    
    return dest;

}

char beBlank(char input){
    char output = input;
    return output;

}



