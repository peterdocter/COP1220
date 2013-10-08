//
//  main.c
//  Chpt5PP7a
//
//  Created by Randy McMillan on 10/7/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   7. a.
 *   Write a program to process a collection of daily high temperatures. Your program should count and print the number of hot days (high tempera- ture 85 or higher), the number of pleasant days (high temperature 60–84), and the number of cold days (high temperatures less than 60). It should also display the category of each temperature. Test your program on the following data:
 *   55  62  68  74  59  45  41  58  60  67  65  78  82  88  91
 *   92  90  93  87  80  78  79  72  68  61  59
 *
 *
 */

#include <stdio.h>
#include <string.h>

#define HOT					85
#define PLEASANT			60
#define CATEGORY_HOT		"hot"
#define CATEGORY_PLEASANT	"pleasant"
#define CATEGORY_COLD		"cold"

void myMain();

void inputTemp();

void calculateCategory(float);

void inputAnotherTemp();

void runProgramAgain();

void printHotDays();

void printPleasantDays();

void printColdDays();

float	temp;
int		hot, pleasant, cold;

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	inputTemp();
	runProgramAgain();
}

void inputTemp()
{
	printf("Please input a temperature --> ");
	scanf("%fl\n", &temp);

	calculateCategory(temp);
	inputAnotherTemp();
}

void calculateCategory(float c)
{
	if (c >= HOT) {
		hot++;
	} else if (c >= PLEASANT) {
		pleasant++;
	} else {cold++; }
}

void inputAnotherTemp()
{
	char yesOrNo[100];

	printf("Would you like to input another temperature? y/n ");
	scanf("%s", yesOrNo);

	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		inputTemp();
	}

	if (strncmp(yesOrNo, "n", 2) == 0) {
		printHotDays();
		printPleasantDays();
		printColdDays();
	}
}

void printHotDays()
{
	printf("\nThere were %i %s days.\n", hot, CATEGORY_HOT);
}

void printPleasantDays()
{
	printf("\nThere were %i %s days.\n", pleasant, CATEGORY_PLEASANT);
}

void printColdDays()
{
	printf("\nThere were %i %s days.\n\n", cold, CATEGORY_COLD);
}

void runProgramAgain()
{
	char yesOrNo[100];

	printf("Would you like to run the program again? y/n ");
	scanf("%s", yesOrNo);

	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");

		temp		= 0;
		hot			= 0;
		pleasant	= 0;
		cold		= 0;
		myMain();
	}

	if (strncmp(yesOrNo, "n", 2) == 0) {
		printf("\nGood Bye!\n");
	}
}