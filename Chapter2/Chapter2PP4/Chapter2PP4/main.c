//
//  main.c
//  Chapter2PP4
//
//  Created by Randy McMillan on 8/29/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double returnCelcius(double fahrenheitTemp);

int main(int argc, const char * argv[])
{

    double fahrenheit = 0.0;
    double celcius = 0.0;
    
    
    printf("Please enter the tempreature in degrees fahrenheit.\n");
    scanf("%lf",&fahrenheit);
    celcius = returnCelcius(fahrenheit);
    printf("%lf",celcius);
    
    
    // insert code here...
    //printf("Hello, World!\n");
    return 0;
}


double returnCelcius(double fahrenheitTemp){
     double temp = (fahrenheitTemp / 2.0);
    printf("%lf\n",fahrenheitTemp);
    
    return temp;
    
}
