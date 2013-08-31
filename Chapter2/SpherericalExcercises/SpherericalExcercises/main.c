//
//  main.c
//  SpherericalExcercises
//
//  Created by Randy McMillan on 8/30/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double radius;
double circumference;

#define CIRCUMFERENCE_360 360
double R, C, SAS, AC;

double pleaseEnterRadius();

double calculateRadian();

double calculateSAS(double r);

double calculateAC(double sas);

double calculateRadius(double r);

double calculateCircumference(double r);

void welcome()
{
	printf("Welcome to Randy McMillan's Ansi C Sphererical Math Excercises!\n\n");
}

int main(int argc, const char *argv[])
{
	welcome();

	C	= CIRCUMFERENCE_360;
	R	= calculateRadian();

	pleaseEnterRadius();
    circumference = calculateCircumference(radius);
	calculateRadius(circumference);
  
   	printf("Your circle circumference = %lf\n\n", circumference);
   	printf("Your circle radius = %lf\n\n", calculateRadius(circumference));
    
    SAS = calculateSAS(radius);
    AC = calculateAC(radius);
    //printf("Useful constants:\n\n");
	//printf("Radian in degree units = %lf\n", R);
	printf("Surface Area of Sphere on degree units = %lf\n", SAS);
	printf("Area of a Circle in degree units = %lf\n", AC);

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
	 *   R = Radian = 57.295780
	 *
	 *   SAS = 360 * 4 * 1/2R
	 *   SAS/4 = Area Circle = AC
	 *   SAS/1/3R = Volume Sphere = VS
	 *
	 */

	return 0;
}

double pleaseEnterRadius()
{
	printf("Please enter the radius. --> ");
	scanf("%lf", &radius);
   	printf("");
 
	return radius;
}

double calculateRadian()
{
	return R = C / (2.0 * M_PI);
}

double calculateSAS(double r)
{
	//printf("Useful constants \n");
	//printf("\n");
	//printf("\n");
	//printf("\n");

	//double	Pi			= M_PI;
	//double	halfPi		= M_PI_2;
	//double	quarterPi	= M_PI_4;
	//double	thirdPi		= M_PI * 0.3333333333333;
	//printf("Pi = %f", Pi);
	//printf("halfPi = %f", halfPi);
	//printf("quarterPi = %f", quarterPi);
	//printf("thirdPi = %f ", thirdPi);
	//double dbPi = (2 * M_PI);
	//printf("dbPi = %f", dbPi);
	//double invDbPi = 1 / (2 * M_PI);
	//printf("invDbPi = %f", invDbPi);

	// double Radian = 360 / dbPi;
	// printf("Radian = %f", Radian);
	// double R = Radian;
	//printf("R = Radian = %f\n", R);
	// double thirdRadian = R*0.33333333;
	// printf("thirdRadian = %f",thirdRadian);
	// double halfRadian = R*0.5;
	// printf("halfRadian = %f",halfRadian);
	// int Circumference = 360;// in degrees
	//printf("Circumference in degrees = %lf\n", C);

	//printf("\n");
	//printf("\n");
	//printf("\n");
	//printf("Proportions of a Sphere \n");
	//printf("\n");
	//printf("\n");
	//printf("\n");

	//printf("360 / 4π = %f = Radian * 1/2\n", (R / 2));

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
	 *   R = Radian = 57.295780
	 *
	 *   SAS = 360 * 4 * 1/2R
	 *   SAS/4 = Area Circle = AC
	 *   SAS/1/3R = Volume Sphere = VS
	 *
	 */

	//SAS = (C * 4) * (0.5 * R);
	//printf("\n");
	//printf("SAS = Surface Area of Sphere \n");
	//printf("\n");
	//printf("SAS = %f", SAS);
	//printf("\n");

	// double AC = (360*(0.5*R));//or SAS/4
	//double AC = M_PI * pow(R, 2);	// or SAS/4
    //printf("Area of a circle in degree units           = %F", AC);
	//printf("\n");
	//printf("Area of a circle in degree units = SAS/4   = %F", (SAS / 4));

	//double VS = ((4 * M_PI) * (pow(R, 3)) / 3);
	//printf("\n");
	//printf("Volume Sphere in degree units              = %f \n", VS);
	//printf("\n");
	//printf("Volume Sphere in degree units = SAS * 1/3R = %f \n", SAS * ((0.3333333333333) * R));	// SAS*1/3R

	// printf("\n");
	// printf("\n");

	// printf("\n");
	// printf("Ratios of 1/(2π) or 1 / Double Pi");
	// printf("\n");
	// printf("\n");
	// printf("\n");

	/*
	 *
	 *   for (int i = 0; i < 5; i++) {
	 *    double	multipleRatio	= pow(dbPi, i) / pow(dbPi, i + 1);
	 *    int		iPlus1			= i + 1;
	 *    printf("\n");
	 *    printf("2π^%i / 2π^%i = %f", i, iPlus1, multipleRatio);
	 *    double multipleRatioTimesDbPi = (pow(dbPi, i) / pow(dbPi, i + 1)) * dbPi;
	 *    printf("\n");
	 *
	 *    printf("(2π^%i / 2π^%i)*2π = %f", i, iPlus1, multipleRatioTimesDbPi);
	 *   }
	 *   printf("\n");
	 *   printf("Ad Inifinitum... \n");
	 *   printf("\n");
	 *
	 *   //
	 *
	 *   printf("\n");
	 *   printf("\n");
	 *   printf("\n");
	 *
	 */

    
    // r^2 * π * 4 = Surface Area of a Sphere
    //printf("%lf\n", pow(r, 2)*M_PI*4.0);
    
	return (C * 4) * (0.5 * (r/R));
}

double calculateAC(double r){
   
    
    //SAS/4 = Area Circle = AC

    
    //*   SAS = 360 * 4 * 1/2R
    //*   SAS/4 = Area Circle = AC
    //*   SAS/1/3R = Volume Sphere = VS
   
    
    /*
	 *
	 *   Traditional Formulas
	 *   r = radius
	 *   r^2 * π = Area Circle
	 *   r^2 * π * 4 = Surface Area of a Sphere
	 *   (4π * r^3)/3 = Volume of a Sphere
	 *
	 */
    
    // r^2 * π * 4 = Surface Area of a Sphere
    //printf("Area Circle = %lf\n", M_PI*pow(r, 2));
    
    return (C * 4) * (0.5 * (r/R))/4;
}

double calculateRadius(double c){

    return radius = (c/360)*R;
    
}

double calculateCircumference(double r){

    
    //printf("Circumference Circle = %lf\n", 2*M_PI*r);
    return (r/R)*C;
    
}