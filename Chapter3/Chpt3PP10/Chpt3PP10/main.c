//
//  main.c
//  Chpt3PP10
//
//  Created by Randy McMillan on 9/14/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
float calcCelcius(float depth);
float calcFarenheit(float depth);


int main(int argc, const char * argv[])
{

    printf("Please enter a depth");
    float depth = 0;
    scanf("%f", &depth);
 
    float celcius = calcCelcius(depth);
    
    printf("It is %0.2f degrees Celcius at that depth.",celcius);
    
    // insert code here...
    //printf("Hello, World!\n");
    return 0;
}

float calcCelcius(float depth){

    float celcius = 10*depth+20;
    
    return celcius;

}

float calcFarenheit(float depth){
    
    float farenheit = 0;
    
    
    
    return farenheit;

}
