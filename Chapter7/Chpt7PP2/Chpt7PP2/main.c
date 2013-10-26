//
//  main.c
//  Chpt7PP2
//
//  Created by Randy McMillan on 10/26/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

//2. Write a C program that fills an array with 100 random* numbers between 0 and 1. Then, go through the array and count how many numbers are <0.5 and how many are >= 0.5. Display the contents of the array and the two count totals.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SENTINEL = -1;

void myMain();
void populateArray();
float returnRand();
float returnClock();
float array[100];
int greaterThan05,lessThan05;

int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}

void myMain(){
    
    populateArray();

}

void populateArray(){
    
    for (int i=0; i<=100; i++) {
        //we know this isn't true random
        array[i]=returnRand();
        printf("%lf\n",array[i]);
    }

}


float returnRand(){
    
    //printf("clock() = %lf\n",returnClock());
    //printf ( "fmod of clock() / clock() is %f\n", fmod (returnClock(),returnClock()) );
    double clock = returnClock();
    clock = clock/10;
    int intpart = (int)clock;
    double decpart = clock - intpart;
    printf("\nclock = %f, myInteger = %d, myDecimal = %f\n", clock, intpart, decpart);
    
    
    float r=rand();
    if (r>1) {
        printf("62 - %lf\n",r);
        r=r/RAND_MAX;
        printf("64 - %lf\n",r);
    }
    
    if (r==0.000008){
        returnRand();
        //printf("69 - %lf\n",r);
    }
    return intpart;

}


float returnClock(){
    return clock();
}
