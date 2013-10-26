//
//  main.c
//  Chpt7PP1
//
//  Created by Randy McMillan on 10/26/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

//1. Write a C program that lets a user enter up to 15 numbers (it will stop accepting numbers either because of a sentinel value or because it reaches the limit of 15 numbers). Display the entered numbers in reverse order (the opposite order in which they were entered).

#include <stdio.h>
#define SENTINEL = -1;

double array[15];
void myMain();

int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}

void myMain(){

    for (int i=0; i<=14; i++) {
        //
        printf("Let array[%i] in the array = ",i);
        scanf("%lf",&array[i]);
        
    }
    
    
}

