//
//  main.c
//  Chpt9PP2
//
//  Created by Randy McMillan on 11/3/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
  2. A palindrome consists of a word or deblanked, unpunctuated phrase that is spelled exactly the same when the letters are reversed. Write a recursive func- tion that returns a value of 1 if its string argument is a palindrome. Notice that in palindromes such as level, deed, sees, and Madam I’m Adam (madamimadam), the first letter matches the last, the second matches the next-to-last, and so on.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE	80
#define ZERO	0
#define BLANK	' '
char	input[LINE];
char	output[LINE];
int num = 0;

void myMain();

void promptInput();

int determinePalindrone(char *string);

void deBlank(char *input, char *output, int loopLength);

char *scanLine(char *dest, int dest_len);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	promptInput();
	deBlank(scanLine(input, LINE), output, (int)strlen(input) + 1);
	//printf("\n%s\n", output);
    printf("\n%i\n",determinePalindrone(output));
    
    
    
    
}

void promptInput()
{
	printf("Please enter a string to be analyzed --> ");
}

void deBlank(char *input, char *output, int loopLength)
{
	// mind my p's and q's
	int p	= ZERO;
	int q	= ZERO;
    
	while (p < loopLength) {
		if (input[p] != BLANK) {	// if not blank
			output[q] = input[p];
			q++;					// increment output index by one when true
		}
        
		p++;// traverse array
	}
}


int determinePalindrone(char *string){
    
    
    size_t sizeEquals = strlen(string);

    long counter = counter + sizeEquals;
    printf("counter = %ld",counter);
    long length = strlen(string);
    
    if (1) {
        //
        printf("%s -> converted to %s length = %ld",input,string,length);
        
    }
    
    
    
    
    
    return num;
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
