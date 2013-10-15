//
//  main.c
//  Chpt6PP1
//
//  Created by Randy McMillan on 10/15/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//


/*
 
 
 1. Write a program for an automatic teller machine that dispenses money.
 The user should enter the amount desired (a multiple of 10 dollars) and the machine dispenses this amount using the least number of bills. The bills dis- pensed are 50s, 20s, and 10s. Write a function that determines how many of each kind of bill to dispense.
 
 
 */
#include <stdio.h>

float amount;
int fifties,twneties,tens,fives,ones;
float cents;

void inputAmount();
void parseBills();

void myMain();

int main(int argc, const char * argv[])
{

    myMain();
    return 0;
}

void myMain(){


    // printf("PLease...");
    //scanf("%f",&amount);
    //printf("amount %f",amount);

    inputAmount();
    
    
}

void inputAmount(){

    
    printf("Please enter amount to be parsed --> ");
    scanf("%f",&amount);
    printf("amount %.2f\n",amount);

    


}