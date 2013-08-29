//
//  main.c
//  Chapter2PP4
//
//  Created by Randy McMillan on 8/29/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define FIVE_NINTHS 5.0 / 9.0

double returnCelcius(double fahrenheitTemp);

int main(int argc, const char *argv[])
{
	double	fahrenheit	= 0.0;
	double	celcius		= 0.0;

	printf("Please enter the tempreature in degrees fahrenheit.\n");
	scanf("%lf", &fahrenheit);
	celcius = returnCelcius(fahrenheit);
	printf("%lf degrees Fahrenheit is %lf Celsius",fahrenheit, celcius);

	return 0;
}

double returnCelcius(double fahrenheitTemp)
{
	double temp = (FIVE_NINTHS * (fahrenheitTemp - 32));

	//printf("%lf\n", fahrenheitTemp);

	return temp;
}
