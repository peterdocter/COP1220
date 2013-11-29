//
//  main.c
//  Chpt11PP5
//
//  Created by Randy McMillan on 11/28/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//
/*
 
 5. Write a program that takes words from a text file and prints each one on a separate line of an output file followed by the number of letters (alphabetic characters) in the word. Any leading or trailing punctuation marks should be removed from the word before it is printed. When all the text has been processed, display on the screen a count of the words in the file. Assume that words are groups of nonwhitespace characters separated by one or more whitespace characters.
 
 
 */


#include <stdio.h>



char name_txt_in[50],
name_bin_out[50];
FILE *text_inp, *text_outp;


void myMain();
void openFiles();
void closeFiles();
int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}


void myMain(){
    
    openFiles();
    closeFiles();
 
}


void openFiles(){

    text_inp = fopen("abc.txt", "r");
    text_outp = fopen("result.txt", "w");
    
    if (text_inp == NULL)
        printf("Cannot open abc.txt for input\n");
    if (text_outp == NULL)
        printf("Cannot open results.txt for input\n");

}

void closeFiles(){

    
    fclose(text_inp);
    fclose(text_outp);
    
    if (text_inp == NULL)
        printf("Closed abc.txt for input\n");
    if (text_outp == NULL)
        printf("Closed results.txt for input\n");

}