//
//  main.c
//  ExtraCredit1
//
//  Created by Randy McMillan on 11/2/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 * 1. An integer n is divisible by 9 if the sum of its digits is divisible by 9.
 *   Develop a program to display each digit, starting with the rightmost digit. Your program should also determine whether or not the number is divisible by 9. Test it on the following numbers:
 *   n = 154368 n = 621594 n = 123456
 *   Hint: Use the % operator to get each digit; then use / to remove that digit. So 154368 % 10 gives 8 and 154368 / 10 gives 15436. The next digit extracted should be 6, then 3 and so on.
 *
 *
 * */
#include <stdio.h>
#include <math.h>

double	input;
int		divisible = 1;
void	myMain();

void calcDivByNine(double);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	printf("input number ---> ");
	scanf("%lf", &input);
	calcDivByNine(input);
	// printf("input - %lf",input);
}

void calcDivByNine(double num)
{
	// double nine = 9.0;

	if ((fmod(num, 9.0) == 0.000000) && (num != 0)) {
		printf("num %lf\n", num);
		printf("TRUE %lf\n", num / 9);
		num			= num / 9;
		divisible	= divisible + 1;
		printf("\ndivisible - %i\n", divisible);
		calcDivByNine(num);
	} else {
		printf("FALSE\n");
		divisible = 0;
		printf("\ndivisible - %i\n", divisible);
	}
}
