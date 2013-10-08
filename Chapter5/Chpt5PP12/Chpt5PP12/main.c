//
//  main.c
//  Chpt5PP12
//
//  Created by Randy McMillan on 10/7/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   12. Assume that United States consumers put $51 billion in fast food charges on their credit and debit cards in 2006, up from $33.2 billion in 2005. Based on this model of the billions of fast food charges,
 *   F(t) = 33.2 + 16.8t
 *   where t is years since 2005, write a program that repeatedly prompts the user to enter a year after 2005 and then predicts the billions of dollars of fast food charges U.S. consumers will make in that year. Define and call a function fast_food_ billions that takes the year as its input argument and returns the prediction as its result. Tell the user that entry of a year before 2005 will cause the program to stop.
 *
 */

#include <stdio.h>
#include <string.h>
#define TWOTHOUSANDANDFIVE 2005
float prediction;

int year;

void myMain();

void inputYear();

void inputAnotherYear();

float fast_food_billions(int);

void outputPrediction(float);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	inputYear();

	// F(t) = 33.2 + 16.8t
	prediction = fast_food_billions(year);

	if (year >= 2005) {
		outputPrediction(prediction);
	} else {
		printf("An input of a year prior to 2005 will not yield an answer.\n");
	}

	inputAnotherYear();
}

void inputYear()
{
	// I could have prompted the user  //Tell the user that entry of a year before 2005 will cause the program to stop.
	printf("Please input a year after 2005 --> ");
	scanf("%i", &year);
}

// F(t) = 33.2 + 16.8t
float fast_food_billions(int t)
{
	return 33.2 + 16.8 * (t - TWOTHOUSANDANDFIVE);
}

void outputPrediction(float p)
{
	printf("%.2lf\n", p);
}

void inputAnotherYear()
{
	// I could have prompted the user  //Tell the user that entry of a year before 2005 will cause the program to stop.
	char yesOrNo[100];

	printf("Would you like to input another year? y/n ");
	scanf("%s", yesOrNo);

	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		myMain();
	}

	if (strncmp(yesOrNo, "n", 2) == 0) {
		printf("Thanks for using this program!\nGood Bye!\n");
		//
		//
	}
}