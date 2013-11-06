//
//  main.c
//  Chpt8PP5
//
//  Created by Randy McMillan on 11/3/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   5. Write a program that takes nouns and forms their plurals on the basis of these rules:
 *   a. If noun ends in “y”, remove the “y” and add “ies”.
 *   b. If noun ends in “s”, “ch”, or “sh”, add “es”.
 *   c. In all other cases, just add “s”.
 *   to quit => 6
 *   to quit => 12 to quit => 0
 *   to quit => -1
 *   Print each noun and its plural. Try the following data:
 *   chair dairy boss circus fly dog church clue dish
 *
 *
 */

#include <stdio.h>
#define ZERO	0
#define LINE	80

void myMain();

void promptInput();

char *scanLine(char *dest, int dest_len);

char	string[LINE];
char	modified[LINE];

char pluralize(char string[LINE]);

char *reverse_string(char *str);

#define Y	"y"
#define S	"s"
// reversed for logic in pluralize()
#define H	"h"
#define C	"c"

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	promptInput();
	scanLine(string, LINE);
	strncpy(modified, string, (size_t)strlen(string));
	// strncpy(modified, modified, 1);
	printf("%c", pluralize(modified));
}

void promptInput()
{
	printf("Please enter a NOUN to be pluralized --> ");
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

char pluralize(char string[LINE])
{
	char	plural	= ' ';
	int		done	= 0;

	while (done != 1) {
		if (!strncmp(reverse_string(string), "y", 1)) {
			reverse_string(string);
			string[strlen(string) - 1] = 0;
			strcat(string, "ies");
			printf("%s\n", string);
			done = 1;
		}

		reverse_string(string);

		// printf("before - %s",string);
		if (!strncmp(reverse_string(string), "s", 1)) {
			reverse_string(string);
			// string[strlen(string)-1] = 0;
			strcat(string, "es");
			printf("%s\n", string);
			done = 1;
		}

		reverse_string(string);

		// printf("before - %s",string);
		if (!strncmp(reverse_string(string), "hc", 2)) {
			reverse_string(string);
			// string[strlen(string)-1] = 0;
			strcat(string, "es");
			printf("%s\n", string);
			done = 1;
		}

		reverse_string(string);

		// printf("before - %s",string);
		if (!strncmp(reverse_string(string), "hs", 2)) {
			reverse_string(string);
			// string[strlen(string)-1] = 0;
			strcat(string, "es");
			printf("%s\n", string);
			done = 1;
		}

		reverse_string(string);

		// printf("before - %s",string);
		if (strncmp(reverse_string(string), "s", 1)) {
			reverse_string(string);
			// string[strlen(string)-1] = 0;
			strcat(string, "s");
			printf("%s\n", string);
			done = 1;
		}
	}

	return plural;
}

///common reverse string technique
char *reverse_string(char *str)
{
	char	temp;
	size_t	len = strlen(str) - 1;
	size_t	i;
	size_t	k = len;

	for (i = 0; i < len; i++) {
		temp	= str[k];
		str[k]	= str[i];
		str[i]	= temp;
		k--;

		if (k == (len / 2)) {
			break;
		}
	}

	return str;
}
