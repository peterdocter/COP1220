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

//Keywords List 32 words
//http://tigcc.ticalc.org/doc/keywords.html
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

//char dictionary[32] = {'0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17'};

//char dictionary[32][10] = {*kwAuto,*kwBreak,*kwCase,*kwChar,*kwConst,*kwContinue,*kwDefault,*kwDo,*kwDouble,*kwElse,*kwEnum,*kwExtern,*kwFloat,*kwFor,*kwGoto,*kwIf,*kwInt,*kwLong,*kwRegister,*kwReturn,*kwShort,*kwSigned,*kwSizeOf,*kwStatic,*kwStruct,*kwSwitch,*kwTypeOf,*kwUnion,*kwUnSigned,*kwVoid,*kwVolatile,*kwWhile};

void    populateDictionary();

float returnRand();
float returnClock();

char keyword[100];
int keywordIndex;

int main(int argc, const char *argv[])
{
    
    keywordIndex = returnRand();
    printf("keywordIndex = %i",keywordIndex);
    populateDictionary();
    //  printf("\nkeyword = %s",&dictionary[keywordIndex]);
    
	return 0;
}


void populateDictionary(){


    if (keywordIndex != 0) {
        
        strncpy(keyword,kwAuto,strlen(kwAuto));
        printf("\nkeyword - %s",&keyword);
    }
    
    
    //printf("\n%s",&dictionary[keywordIndex]);
    //printf("\n%s\n",&dictionary[keywordIndex]);
    
}


///returnRand

float returnRand(){
    
    double clock = returnClock();
    clock = clock/10;
    int intpart = (int)clock;
    double decpart = clock - intpart;
    
    return decpart*10;
}


float returnClock(){
    return clock();
}


