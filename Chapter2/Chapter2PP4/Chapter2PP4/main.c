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
double calculateCelcius(double fahrenheit);

int main(int argc, const char *argv[])
{
	double reimbursement	= 0.0,
    beginning			= 0.100,
    ending				= 0.0,
    
    
    fahrenheit = 0.0,
    celcius = 0.0,
    
    milesTraveled;
    
	// insert code here...
	printf("MILEAGE REIMBERSMENT CALCULATOR\n");
	printf("Enter beggining odometer reading=>\n");
	scanf("%lf", &beginning);
	printf("Enter ending odometer reading=>\n");
	scanf("%lf", &ending);
	milesTraveled = calculateDistanceTraveled(beginning, ending);
	printf("You traveled %lf miles. At $0.35 per mile,\n", milesTraveled);
	reimbursement = calculateReimbersment(milesTraveled);
	printf("your reimbersment is $ %lf\n", reimbursement);
    
    
    
    
    printf("Enter F\n");
	scanf("%lf", &fahrenheit);
	celcius = calculateCelcius(fahrenheit);
	printf("calculateCelcius(fahrenheit) = %lf\n", celcius);
    
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


double calculateCelcius(double fahrenheitTemp){
    
    double temp1 = fahrenheitTemp - 32;
    printf("%lf\n",temp1);
    
    double temp2 = 5.0 / 9.0;
    
    printf("%lf\n",temp2);
    double temp3 = fahrenheitTemp * temp2;
    
    printf("%lf\n",temp3);
    double celciusTemp = temp3;
    
    printf("%lf\n",celciusTemp);
    return celciusTemp;
    

}
