//
//  main.c
//  Chpt6PP1
//
//  Created by Randy McMillan on 10/15/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   1. Write a program for an automatic teller machine that dispenses money.
 *   The user should enter the amount desired (a multiple of 10 dollars) and the machine dispenses this amount using the least number of bills. The bills dis- pensed are 50s, 20s, and 10s. Write a function that determines how many of each kind of bill to dispense.
 *
 *
 */
#include <stdio.h>

float	amount;
int		fifties, twenties, tens, fives, ones;
float	cents;

void inputAmount();

void parseBills(float);
void displayTotals(float);
void myMain();

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	amount		= 0;
	fifties		= 0;
	twenties	= 0;
	tens		= 0;
	fives		= 0;
	ones		= 0;
	cents		= 0;
	// printf("PLease...");
	// scanf("%f",&amount);
	// printf("amount %f",amount);

	inputAmount();
}

void inputAmount()
{
	printf("Please enter amount to be parsed --> ");
	scanf("%f", &amount);
	// printf("amount %.2f\n",amount);

	parseBills(amount);
}

void parseBills(float a)
{
	// printf("parseBills\n");
	// printf("%.2f\n",a);

	if (a / 50 >= 1) {
		fifties = a / 50;
		printf("fifties = %i\n", fifties);
		a = a - (fifties * 50);
		printf("%f\n", a);
	}
    
    if (a / 20 >= 1) {
		twenties = a / 20;
		printf("twenties = %i\n", twenties);
		a = a - (twenties * 20);
		printf("%f\n", a);
	}
    
    if (a / 10 >= 1) {
		tens = a / 10;
		printf("tens = %i\n", tens);
		a = a - (tens * 10);
		printf("%f\n", a);
	}
    
    if (a / 5 >= 1) {
		fives = a / 5;
		printf("fives = %i\n", fives);
		a = a - (fives * 5);
		printf("%f\n", a);
	}

    
    
    if (a / 1 >= 1) {
		ones = a / 1;
		printf("ones = %i\n", ones);
		a = a - (ones * 1);
		//printf("%f\n", a);
	}
    
    displayTotals(a);
}

void displayTotals(float a){
    //printf("%.2lf",a);
    
    printf("$1%.2lf is dispensed in the following denominations:\n%i - Fifties\n%i - T2wenties\n%i - Tens\n%i - Fives\n%i - Ones\nand %.2lf cents\n",amount,fifties,twenties,tens,fives,ones,a);
    

}
