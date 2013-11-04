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

void deBlank(char *input, int loops);

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
}

// Based on Figure 8.15 in Book
char *scanLine(char *dest, int dest_len)
{
	int i, ch;

	i = 0;

	for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
		dest[i++] = ch;

		if (!isspace(ch)) {
			target[i] = ch;
		}
	}

	dest[i] = '\0';

	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}

	return dest;
}

void deBlank(char *input, int loops)
{
	for (int i = 0; i <= loops; i++) {
		if (!strncmp(&target[i], "", 1) == 0) {
			printf("%s", &target[i]);
		}
	}
}
