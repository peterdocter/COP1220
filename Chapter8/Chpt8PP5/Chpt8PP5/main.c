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
#define HS	"hs"
#define HC	"hc"

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
	printf("Please enter a string to be deblanked --> ");
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
	char plural = ' ';

	if (!strncmp(reverse_string(string), Y, 1)) {
		//printf("y - add ies");
        reverse_string(string);
        
        printf("%lu",strlen(string)-1);
        //strncat(string, "sss", strlen(string)-0);
        string[strlen(string)-1] = 0; /* 'P' is not in `p` (and it isn't in `mystr` either) */

        strncpy(string,string,strlen(string)-1);
        //printf("%s",string);

        strcat(string,"ies");
        printf("%s",string);

        //char *strcpy(char *str1, const char *str2);

        
	}

	if (!strncmp(reverse_string(string), HC, 2) || !strncmp(reverse_string(string), HS, 2) || !strncmp(reverse_string(string), S, 1)) {
		//printf("s -  add es\n");
		//printf("ch - add es\n");
		//printf("sh - add es\n");
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
