//
//  main.c
//  Chapt3PP6
//
//  Created by Randy McMillan on 9/11/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   6. Four track stars have entered the mile race at the Penn Relays. Write a pro-
 *   gram that scans in the race time in minutes (minutes) and seconds (seconds) for a runner and computes and displays the speed in feet per second (fps) and in meters per second (mps). (Hints: There are 5,280 feet in one mile, and one kilometer equals 3,282 feet.) Write and call a function that displays instruc- tions to the program user. Run the program for each star’s data.
 *   Minutes Seconds
 *   3         52.83
 *   3         59.83
 *   4         00.03
 *   4         16.22
 *   ￼￼￼
 */

#include <stdio.h>
#define feetMile 5280
#define metersMile 1609.34

double calcFPS(int min, double sec);

double calcMPS(int min, double sec);

void printResults(double fps, double mps);

int main(int argc, const char *argv[])
{
	int first_min	= 3,
		second_min	= 3,
		third_min	= 4,
		fourth_min	= 4;

	double first_sec	= 52.83,
		second_sec		= 59.83,
		third_sec		= 00.03,
		fourth_sec		= 16.22;

	//double minutes	= 0,
	//	seconds		= 0;
/*
	printf("%i,%i,%i,%i,%f,%f,%f,%f,%f,%f\n\n", first_min,
		second_min,
		third_min,
		fourth_min,
		first_sec,
		second_sec,
		third_sec,
		fourth_sec,
		minutes,
		seconds);
*/
    
	///calc feet per second
	printf("%f\n", calcFPS(first_min, first_sec));
	///calc meters per second
	printf("%f\n\n", calcMPS(first_min, first_sec));
    
    
	///calc feet per second
	printf("%f\n", calcFPS(second_min, second_sec));
	///calc meters per second
	printf("%f\n\n", calcMPS(second_min, second_sec));
	
    
	///calc feet per second
	printf("%f\n", calcFPS(third_min, third_sec));
	///calc meters per second
	printf("%f\n\n", calcMPS(third_min, third_sec));
    
    
	///calc feet per second
	printf("%f\n", calcFPS(fourth_min, fourth_sec));
	///calc meters per second
	printf("%f\n\n", calcMPS(fourth_min, fourth_sec));
    
    
    // insert code here...
	//	printf("Hello, World!\n");
	return 0;
}

double calcFPS(int min, double sec)
{
	double fps = 0;

	//printf("%f\n", ((min * 60) + sec));
	fps = feetMile/((min * 60) + sec);
	//printf("%f", fps);
	return fps;
}

double calcMPS(int min, double sec)
{
	double mps = 0;

	//printf("%f\n", ((min * 60) + sec));
	mps = metersMile/((min * 60) + sec);
	//printf("%f", mps);
	return mps;
}

void printResults(double fps, double mps) {}
