//
//  main.c
//  ExtraCredit1
//
//  Created by Randy McMillan on 11/2/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 * 1. An integer n is divisible by 9 if the sum of its digits is divisible by 9.
 *   Develop a program to display each digit, starting with the rightmost digit. Your program should also determine whether or not the number is divisible by 9. Test it on the following numbers:
 *   n = 154368 n = 621594 n = 123456
 *   Hint: Use the % operator to get each digit; then use / to remove that digit. So 154368 % 10 gives 8 and 154368 / 10 gives 15436. The next digit extracted should be 6, then 3 and so on.
 *
 *
 * */
#include <stdio.h>
#include <math.h>

double	input;
int		divisible = 1;
void	myMain();
double ten = 10;
double numArray[];
double sum=0;
int sentinel = 0;
int counter = 0;

void calcDivByNine(int);

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	printf("input number between 0 and 999999999 ---> ");
	scanf("%lf", &input);
	calcDivByNine(input);
   	calcDivByNine(sum);
    //calcDivByNine(sum);
	// printf("input - %lf",input);
}

void calcDivByNine(int num){
    sum=0;
    for (int i = 0; i <= 80; i++) {
        numArray[i]= num % 10;
        printf("numArray[%i] = %i\n",i,(int)numArray[i]);
        num = num/10;
        printf("%i\n",num);
        counter = counter+1;
        printf("counter = %i\n",counter);
    }

    printf("\n______________next for_________________\n");
    
    for (int i =counter-1; i>=0; i--) {
        printf("\ni = %i\n",i);
        printf("numArray[%i] = %lf\n",i,numArray[i]);
        sum = sum + numArray[i];
        numArray[i]=0;
        printf("sum = %lf",sum);
    }
    
    counter = 0;
}
