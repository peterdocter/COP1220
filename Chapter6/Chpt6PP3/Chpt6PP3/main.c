//
//  main.c
//  Chpt6PP3
//
//  Created by Randy McMillan on 10/15/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   3. Write a program to dispense change. The user enters the amount paid and the amount due. The program determines how many dollars, quarters, dimes, nickels, and pennies should be given as change. Write a function with four output parameters that determines the quantity of each kind of coin.
 *
 *
 */

#include <stdio.h>
#include <math.h>

float	amount;
int		hundreds, fifties, twenties, tens, fives, ones, quarters, dimes, nickels, pennies;
float	cents;

int *hundredDollarBills, *fiftyDollarBills, *twentyDollarBills, *tenDollarBills, *fiveDollarBills, *oneDollarBills, *quarterDollars, *tenthDollars, *twentiethDollars, *hundrethsDollars;

float amountPaid, amountDue, difference, change;

void inputDue();

void inputPaid();

void calcDifference(float d, float p);

void calcChange(float a);

void displayTotals(float);

void myMain();

int main(int argc, const char *argv[])
{
	// pointer usage per chapter subject
	// not really neccesary but...
	hundredDollarBills	= &hundreds;
	fiftyDollarBills	= &fifties;
	twentyDollarBills	= &twenties;
	tenDollarBills		= &tens;
	fiveDollarBills		= &fives;
	oneDollarBills		= &ones;
	quarterDollars		= &quarters;
	tenthDollars		= &dimes;
	twentiethDollars	= &nickels;
	hundrethsDollars	= &pennies;

	myMain();
	return 0;
}

void myMain()
{
	inputDue();
	inputPaid();
	calcDifference(amountDue, amountPaid);
	calcChange(difference);
	//displayChange(change);
}

void inputDue()
{
	printf("Please input the amount due ---> ");
	scanf("%f", &amountDue);
}

void inputPaid()
{
	printf("Please input the amount paid ---> ");
	scanf("%f", &amountPaid);
}

void calcDifference(float d, float p)
{
	difference = d - p;

	if (d < p) {
        
		//convert to absolute value before sending to next function
        difference = fabs(difference);
		
	} else {
		// a bit of error checking
		printf("Please reenter the amounts.\n");
		myMain();
	}
}

void calcChange(float a)
{
	// a = fabsf(a);
	// printf("calcChange\n");
	// printf("%.2f\n",a);

	if (a / 100 >= 1) {
		*hundredDollarBills = a / 100;
		printf("hundreds = %i\n", hundreds);
		a = a - (*hundredDollarBills * 100);
		printf("%f\n", a);
	}

	if (a / 50 >= 1) {
		*fiftyDollarBills = a / 50;
		printf("fifties = %i\n", fifties);
		a = a - (*fiftyDollarBills * 50);
		printf("%f\n", a);
	}

	if (a / 20 >= 1) {
		*twentyDollarBills = a / 20;
		printf("twenties = %i\n", twenties);
		a = a - (*twentyDollarBills * 20);
		printf("%f\n", a);
	}

	if (a / 10 >= 1) {
		*tenDollarBills = a / 10;
		printf("tens = %i\n", tens);
		a = a - (*tenDollarBills * 10);
		printf("%f\n", a);
	}

	if (a / 5 >= 1) {
		*fiftyDollarBills = a / 5;
		printf("fives = %i\n", fives);
		a = a - (*fiftyDollarBills * 5);
		printf("%f\n", a);
	}

	if (a / 1 >= 1) {
		*oneDollarBills = a / 1;
		printf("ones = %i\n", ones);
		a = a - (*oneDollarBills * 1);
		printf("%f\n", a);
	}

	if (a / 1 < 1) {
    
    
        printf("small change - %lf\n",a);
        
        if (a / .25 >= 1) {
            *quarterDollars = a / .25;
            printf("quarters = %i\n", quarters);
            a = a - (*quarterDollars * .25);
              printf("%f\n", a);
        }
    
        if (a / .10 >= 1) {
            *tenthDollars = a / .10;
            printf("dimes = %i\n", dimes);
            a = a - (*tenthDollars * .10);
            printf("%f\n", a);
        }
        
        if (a / .05 >= 1) {
            *twentiethDollars = a / .05;
            printf("nickels = %i\n", nickels);
            a = a - (*twentiethDollars * .05);
            printf("%f\n", a);
        }

        if (a / .01 >= 1) {
            *hundrethsDollars = a / .01;
            printf("pennies = %i\n", pennies);
            a = a - (*hundrethsDollars * .01);
            printf("%f\n", a);
        }



    
    
    }
    
    displayTotals(a);

}

void displayTotals(float a){
    //printf("%.2lf",a);
    
    printf("\n$%.2lf is dispensed in the following denominations:\n%i - Fifties\n%i - Twenties\n%i - Tens\n%i - Fives\n%i - Ones\nand %.2lf cents\n",amount,*fiftyDollarBills,*twentyDollarBills,*tenDollarBills,*fiveDollarBills,*oneDollarBills,a);
    
}