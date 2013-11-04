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
#include <ctype.h>
#include <string.h>
#define LINE 80

void myMain();

void inPut();

char deBlank(char *input, int loops);

char	line[LINE];
char	target[LINE];
char	*scanLine(char *dest, int dest_len);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	inPut();
	deBlank(target, LINE);
}

void inPut()
{
	printf("Please enter a line of text --> ");
	
    scanLine(line, LINE);
    //printf("%s\n", scanLine(line, LINE));

}

// Based on Figure 8.15 in Book
char *scanLine(char *dest, int dest_len)
{
	int i, ch;

	i = 0;

	for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
		dest[i++] = ch;

		if (!isspace(ch)) {
			// printf("\n!isspace - %c\n",ch);
			target[i] = ch;
		}

		// dest[i++] = ch;
	}

	dest[i] = '\0';

	/* Discards any characters that remain on input line */
	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}

	return dest;
}

char deBlank(char *input, int loops)
{
	char *output = input;

	for (int i = 0; i <= loops; i++) {
		// printf("\n%i\n",i);
		// printf("\ntarget[%i] = %s\n",i,&target[i]);

		//      if (strncmp(&target[i], "y", 2) == 0) {
		if (!strncmp(&target[i], "", 1) == 0) {
			//
			// printf("true");
			printf("%s", &target[i]);
		}
	}

	// printf("\nline = %s\n", line);
	return *output;
}
