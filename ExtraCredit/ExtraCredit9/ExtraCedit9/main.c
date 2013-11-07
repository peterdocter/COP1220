//
//  main.c
//  ExtraCredit9
//
//  Created by Randy McMillan on 11/2/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   9. Write an interactive program that plays a game of hangman. Store the word to be guessed in successive elements of an array of individual characters called word. The player must guess the letters belonging to word. The program should terminate when either all letters have been guessed correctly (the player wins) or a specified number of incorrect guesses have been made (the compu- ter wins). Hint: Use another array, guessed, to keep track of the solution so far. Initialize all elements of guessed to the '*' symbol. Each time a letter in word is guessed, replace the corresponding '*' in guessed with that letter.
 *
 *
 */

/*
 *   //ANSI C keyword strings
 *
 *   auto
 *   break
 *   case
 *   char
 *   const
 *   continue
 *   default
 *   do
 *   double
 *   else
 *   enum
 *   extern
 *   float
 *   for
 *   goto
 *   if
 *   int
 *   long
 *   register
 *   return
 *   short
 *   signed
 *   sizeof
 *   static
 *   struct
 *   switch
 *   typedef
 *   union
 *   unsigned
 *   void
 *   volatile
 *   while
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Keywords List 32 words
// http://tigcc.ticalc.org/doc/keywords.html
char	kwAuto[]		= "auto";
char	kwBreak[]		= "break";
char	kwCase[]		= "case";
char	kwChar[]		= "char";
char	kwConst[]		= "const";
char	kwContinue[]	= "continue";
char	kwDefault[]		= "default";
char	kwDo[]			= "do";
char	kwDouble[]		= "double";
char	kwElse[]		= "else";
char	kwEnum[]		= "enum";
char	kwExtern[]		= "extern";
char	kwFloat[]		= "float";
char	kwFor[]			= "for";
char	kwGoto[]		= "goto";
char	kwIf[]			= "if";
char	kwInt[]			= "int";
char	kwLong[]		= "long";
char	kwRegister[]	= "register";
char	kwReturn[]		= "return";
char	kwShort[]		= "short";
char	kwSigned[]		= "signed";
char	kwSizeOf[]		= "sizeof";
char	kwStatic[]		= "static";
char	kwStruct[]		= "struct";
char	kwSwitch[]		= "switch";
char	kwTypeOf[]		= "typeof";
char	kwUnion[]		= "union";
char	kwUnSigned[]	= "unsigned";
char	kwVoid[]		= "void";
char	kwVolatile[]	= "volatile";
char	kwWhile[]		= "while";

// char dictionary[32] = {'0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17'};

// char dictionary[32][10] = {*kwAuto,*kwBreak,*kwCase,*kwChar,*kwConst,*kwContinue,*kwDefault,*kwDo,*kwDouble,*kwElse,*kwEnum,*kwExtern,*kwFloat,*kwFor,*kwGoto,*kwIf,*kwInt,*kwLong,*kwRegister,*kwReturn,*kwShort,*kwSigned,*kwSizeOf,*kwStatic,*kwStruct,*kwSwitch,*kwTypeOf,*kwUnion,*kwUnSigned,*kwVoid,*kwVolatile,*kwWhile};

void populateDictionary();

float returnRand();

float returnClock();

char	keyword[100];
int		keywordIndex;


void printKeywordSubs(char word[],int i);
    
int main(int argc, const char *argv[])
{
	keywordIndex = returnRand();
	printf("keywordIndex = %i", keywordIndex);
	populateDictionary();
	//  printf("\nkeyword = %s",&dictionary[keywordIndex]);
    printKeywordSubs(keyword,strlen(keyword)-1);
	return 0;
}



void printKeywordSubs(char word[],int i){

    for (int i = 0; i< strlen(word) ; i++) {
        //
        
        printf("\nc = %c",word[i]);
        
    }


}


void populateDictionary()
{
	if (keywordIndex == 0) {
		strncpy(keyword, kwAuto, strlen(kwAuto));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 1) {
		strncpy(keyword, kwBreak, strlen(kwBreak));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 2) {
		strncpy(keyword, kwCase, strlen(kwCase));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 3) {
		strncpy(keyword, kwChar, strlen(kwChar));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 4) {
		strncpy(keyword, kwConst, strlen(kwConst));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 5) {
		strncpy(keyword, kwContinue, strlen(kwContinue));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 6) {
		strncpy(keyword, kwDefault, strlen(kwDefault));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 7) {
		strncpy(keyword, kwDo, strlen(kwDo));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 8) {
		strncpy(keyword, kwDouble, strlen(kwDouble));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 9) {
		strncpy(keyword, kwElse, strlen(kwElse));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 10) {
		strncpy(keyword, kwEnum, strlen(kwEnum));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 11) {
		strncpy(keyword, kwExtern, strlen(kwExtern));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 12) {
		strncpy(keyword, kwFloat, strlen(kwFloat));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 13) {
		strncpy(keyword, kwFor, strlen(kwFor));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 14) {
		strncpy(keyword, kwGoto, strlen(kwGoto));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 15) {
		strncpy(keyword, kwIf, strlen(kwIf));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 16) {
		strncpy(keyword, kwInt, strlen(kwInt));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 17) {
		strncpy(keyword, kwLong, strlen(kwLong));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 18) {
		strncpy(keyword, kwRegister, strlen(kwRegister));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 19) {
		strncpy(keyword, kwReturn, strlen(kwReturn));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 20) {
		strncpy(keyword, kwShort, strlen(kwShort));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 21) {
		strncpy(keyword, kwSigned, strlen(kwSigned));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 22) {
		strncpy(keyword, kwSizeOf, strlen(kwSizeOf));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 23) {
		strncpy(keyword, kwStatic, strlen(kwStatic));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 24) {
		strncpy(keyword, kwStruct, strlen(kwStruct));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 25) {
		strncpy(keyword, kwSwitch, strlen(kwSwitch));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 26) {
		strncpy(keyword, kwTypeOf, strlen(kwTypeOf));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 27) {
		strncpy(keyword, kwUnion, strlen(kwUnion));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 28) {
		strncpy(keyword, kwUnSigned, strlen(kwUnSigned));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 29) {
		strncpy(keyword, kwVoid, strlen(kwVoid));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 30) {
		strncpy(keyword, kwVolatile, strlen(kwVolatile));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 31) {
		strncpy(keyword, kwWhile, strlen(kwWhile));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 32) {
		strncpy(keyword, kwAuto, strlen(kwAuto));
		printf("\nkeyword - %s", &keyword);
	}

	if (keywordIndex == 33) {
		strncpy(keyword, kwAuto, strlen(kwAuto));
		printf("\nkeyword - %s", &keyword);
	}

	// printf("\n%s",&dictionary[keywordIndex]);
	// printf("\n%s\n",&dictionary[keywordIndex]);
}

///returnRand

float returnRand()
{
	double clock = returnClock();

	clock = clock / 10;
	int		intpart = (int)clock;
	double	decpart = clock - intpart;

	return decpart * 10;
}

float returnClock()
{
	return clock();
}
