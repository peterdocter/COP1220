//
//  main.c
//  SpherericalExcercises
//
//  Created by Randy McMillan on 8/30/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

// http://en.wikipedia.org/wiki/Sphere

#include <stdio.h>
#include <math.h>
#include <string.h>

#define CIRCUMFERENCE_360 360

double radius;

double circumference;

double R, C, SAS, AC, VS;

void pleaseEnterRadius();

double calculateRadian();

double calculateSAS(double r);

double calculateAC(double r);

double calculateRadius(double r);

double calculateCircumference(double r);

double calculateVolumeSphere(double r);

void calculateCircle();

char yesOrNo;

void welcome()
{
	printf("Welcome to Randy McMillan's Ansi C Sphererical Math Excercises!\n\n");
	pleaseEnterRadius();
}

void pleaseEnterRadius()
{
	printf("Please enter the radius. --> ");
	scanf("%lf", &radius);
	printf("\n");
	// return radius;
}

int main(int argc, const char *argv[])
{
	calculateCircle();
	return 0;
}

void calculateCircle()
{
	welcome();

	C = CIRCUMFERENCE_360;
	calculateRadian();

	circumference = calculateCircumference(radius);
	// calculateRadius(circumference);

	printf("Circumference of Circle/Sphere = %lf\n\n", circumference);
	// printf("Your circle radius = %lf\n\n", calculateRadius(circumference));

	AC = calculateAC(radius);
	printf("Area of a Circle = %lf\n\n", AC);

	SAS = calculateSAS(radius);
	printf("Surface Area of Sphere  = %lf\n\n", SAS);

	VS = calculateVolumeSphere(radius);
	printf("Volume of Sphere  = %lf\n\n", VS);

	char yesOrNo[100];
	printf("Would you like to calculate another? y/n ");
	scanf("%s", yesOrNo);

	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		calculateCircle();
	}

	if (strncmp(yesOrNo, "n", 2) == 0) {
		printf("Good bye!");
	}

}

double calculateRadian()
{
	return R = C / (2.0 * M_PI);
}

double calculateSAS(double r)
{
	return (C * 4) * (0.5 * (r / R));
}

double calculateAC(double r)
{
	// printf("Area of cir %lf\n",M_PI*pow(r, 2));
	return (C * 4) * (0.5 * (r / R)) / 4;
}

double calculateRadius(double c)
{
	// printf("%lf\n",c/2.0/M_PI);
	return radius = (c / 360) * R;
}

double calculateCircumference(double r)
{
	// printf("Circumference Circle = %lf\n", 2*M_PI*r);
	return (r / R) * C;
}

double calculateVolumeSphere(double r)
{
	// printf("%lf\n",((4.0/3.0) * M_PI * pow(r, 3)));
	return calculateSAS(r) / 3;
}

/*
 *
 *   Traditional Formulas
 *   r = radius
 *   r^2 * π = Area Circle
 *   r^2 * π * 4 = Surface Area of a Sphere
 *   (4π * r^3)/3 = Volume of a Sphere
 *
 */

/*
 *
 *   //Radian Based
 *
 *   R = Radian = 57.25977951
 *
 *   SAS = 360 * 4 * 1/2R
 *   SAS/4 = Area Circle = AC
 *   SAS/1/3R = Volume Sphere = VS
 *
 */
