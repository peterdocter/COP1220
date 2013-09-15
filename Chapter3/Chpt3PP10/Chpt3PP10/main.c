//
//  main.c
//  Chpt3PP10
//
//  Created by Randy McMillan on 9/14/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

#include <stdio.h>
#include <string.h>


float celcius_at_depth(float depth);
float farenheit(float depth);

void calculate();
    
int main(int argc, const char * argv[])
{
    calculate();
    return 0;
}


void calculate(){

    printf("Please enter a depth --> ");
    float depth = 0;
    scanf("%f", &depth);
    float celcius = celcius_at_depth(depth);
    printf("It is %0.2f degrees Celcius at that depth.\n",celcius);
    printf("It is %0.2f degrees Fahernheit at that depth.",farenheit(celcius));
    // insert code here...
    //printf("Hello, World!\n");
    
    
    char yesOrNo[100];
	printf("Would you like to calculate another? y/n ");
	scanf("%s", yesOrNo);
    
	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		calculate();
	}
    
	if (strncmp(yesOrNo, "n", 2) == 0) {
		printf("Good bye!");
	}
}

float celcius_at_depth(float depth){

    float celcius = 10*depth+20;
    return celcius;
}

float farenheit(float celcius){
    
    float farenheit = 1.8*celcius+32;
    return farenheit;
}
