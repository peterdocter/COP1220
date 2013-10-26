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

#define SENTINEL = -1;

void myMain();
void populateArray();
float returnRand();

float array[100];
int greaterThan05,lessThan05;

int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}

void myMain(){

    
    time_t timer;
    
    timer=time(NULL);
    printf("The current time is %s.\n",asctime(localtime(&timer)));
    clock_t uptime = clock() / (CLOCKS_PER_SEC / 1000);
    printf("uptime = %lo",uptime);
    populateArray();

}

void populateArray(){
    clock_t uptime = clock() / (CLOCKS_PER_SEC / 1000);
    printf("uptime = %lo",uptime);
    
    for (int i=0; i<=100; i++) {
        //we know this isn't true random
        array[i]=returnRand();
        printf("%lf\n",array[i]);
    }

}


float returnRand(){
    clock_t uptime = clock() / (CLOCKS_PER_SEC / 1000);
    printf("uptime = %lo",uptime);
    float r=rand();
    if (r>1) {
        //printf("%lf\n",r);
        r=r/RAND_MAX;
        //printf("%lf\n",r);
    }
    return r;

}





