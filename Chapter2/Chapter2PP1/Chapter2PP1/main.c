//
//  main.c
//  Chapter2PP1
//
//  Created by Randy McMillan on 8/29/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
double calculateDistanceTraveled(double beginning, double ending);

double calculateReimbersment(double milesTraveled);

int main(int argc, const char *argv[])
{
	float reimbursement	= 0.0,
		beginning			= 0.100,
		ending				= 0.0,
		milesTraveled;

	// insert code here...
	printf("MILEAGE REIMBERSMENT CALCULATOR\n");
	printf("Enter beggining odometer reading=> ");
	scanf("%f", &beginning);
	printf("Enter ending odometer reading=> ");
	scanf("%f", &ending);
	milesTraveled = calculateDistanceTraveled(beginning, ending);
	printf("You traveled %lf miles. At $0.35 per mile,\n", milesTraveled);
	reimbursement = calculateReimbersment(milesTraveled);
	printf("your reimbersment is $ %5.2f\n", reimbursement);
	return 0;
}

double calculateDistanceTraveled(double beginning, double ending)
{
	double temp = ending - beginning;

	return temp;
}

double calculateReimbersment(double milesTraveled)
{
	double tempReimbursment = milesTraveled * 0.35;

	return tempReimbursment;
}
