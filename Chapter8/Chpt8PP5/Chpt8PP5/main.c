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
#define Y 'y'
#define S 's'
#define SH 'sh'
#define CH 'ch'
#define ES 'es'


void myMain();

void promptInput();

char *scanLine(char *dest, int dest_len);

char string[LINE];
char modified[LINE];

char pluralize(char string);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	promptInput();
	scanLine(string, LINE);
    strncpy(modified, string,(size_t)strlen(string));
    //strncpy(modified, modified, 1);

    
    //printf("%s",strrchr (modified, 'sl'));

    if (strrchr(modified, Y)) {
        printf("y");
    }
    
    if (strrchr(modified, S)) {
        printf("s");
    }
    
    if (strrchr(modified, CH)) {
        printf("ch");
    }
    
    if (strrchr(modified, SH)) {
        printf("sh");
    }
    
    if (strrchr(modified, ES)) {
        printf("es");
    }
    
    //printf("%s",&modified[0]);
	//printf("%lu\n", strlen(string));
    //for (int i = strlen(modified); i <= strlen(modified); i--) {
        	//printf("%i", i);
            
    //         printf("%s",strrchr (modified, 'sl'));
            //=> "ld"
            //  }


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

char pluralize(char string)
{
	char plural = ' ';

	return plural;
}
