//
//  main.c
//  Chpt11PP5
//
//  Created by Randy McMillan on 11/28/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   5. Write a program that takes words from a text file and prints each one on a separate line of an output file followed by the number of letters (alphabetic characters) in the word. Any leading or trailing punctuation marks should be removed from the word before it is printed. When all the text has been processed, display on the screen a count of the words in the file. Assume that words are groups of nonwhitespace characters separated by one or more whitespace characters.
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

char name_txt_in[50],
	name_bin_out[50];
FILE	*text_inp, *text_outp;
char	ch;

void myMain();

void openFiles();

void closeFiles();

void copyChars();

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	openFiles();

	copyChars();

	closeFiles();
	printf("\n");
}

void copyChars()
{
	int c	= 0;
	int n	= 1;
    char new_str;
    
	// Make backup copy one character at a time
	for (ch = getc(text_inp); ch != EOF; ch = getc(text_inp)) {
		if (strcmp(&ch, ".")) {
			//            printf("%i ",n);

			if (strcmp(&ch, " ")) {
				putc(ch, text_outp);
               

				printf("%c", ch);
                
                
			
            } else {
                
                 char dig = '0'+c;
                //char dig = (char)(((int)'0')+c);
                //printf("%c", dig);
                putc(' ',text_outp);
				putc(dig, text_outp);
				putc('\n', text_outp);
				printf(" %i\n", c);
				c = -1;
				n++;
			}
		}

		c++;
	}
    
    
    char dig = '0'+c;
    //char dig = (char)(((int)'0')+c);
    //printf("%c", dig);
    putc(' ',text_outp);
    putc(dig, text_outp);

    
    
    printf(" %i\n", c-1);//final c

	printf("\nThere are %i words in the file.\n", n);
}

void openFiles()
{
	char	buff[100];
	time_t	now = time(0);

	strftime(buff, 100, "%Y-%m-%d %H:%M:%S", localtime(&now));
	// printf("%s\n", buff);

	text_inp	= fopen("abc.txt", "r");
	text_outp	= fopen(__DATE__ "_"__TIME__ ".txt", "w");	// unique file name
	// text_outp	= fopen(__DATE__"result.txt", "w");

	if (text_inp == NULL) {
		printf("Cannot open abc.txt for input\n");
	}

	if (text_outp == NULL) {
		printf("Cannot open results.txt for input\n");
	}
}

void closeFiles()
{
	fclose(text_inp);
	fclose(text_outp);
}
