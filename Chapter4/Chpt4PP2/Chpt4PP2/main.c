//
//  main.c
//  Chpt4PP2
//
//  Created by Randy McMillan on 9/26/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 
 2. Write a program that calculates the user’s body mass index (BMI) 
 and catego- rizes it as underweight, normal, overweight, or obese, 
 based on the following table from the United States Centers for 
 Disease Control:

    BMI            Weight Status
    ----------------------------
    Below 18.5     Underweight

    18.5–24.9      Normal

    25.0–29.9      Overweight

    30.0           Obese
 
￼￼  To calculate BMI based on weight in pounds (wt_lb) 
    and height in inches (ht_in), use this formula (rounded to tenths):
                    
                    703 * wt_lb ht_in2
 
Prompt the user to enter weight in pounds and height in inches.

 */

#include <stdio.h>

float weight,height,bmi;
float returnBMI(float w,float h);
void calculate();

int main(int argc, const char * argv[]){
    
    calculate();
    return 0;

}

void calculate(){
    
    printf("Please enter the person's weight in pounds --> ");
    scanf("%f",&weight);
    printf("Please enter the person's height in inches --> ");
    scanf("%f",&height);

    bmi = returnBMI(weight, height);
    //printf("%f\n",bmi);
    
    if (bmi<18.5) {
    
        printf("The person's BMI = %f and is considered Underweight by the US CDC.\n",bmi);

    } else if (bmi < 25) {
    
        printf("The person's BMI = %f and is considered Normal by the US CDC.\n",bmi);
    
    } else if (bmi < 30) {
    
        printf("The person's BMI = %f and is considered Overweight by the US CDC.\n",bmi);
    
    } else {
    
        printf("The person's BMI = %f and is considered Obese by the US CDC.\n",bmi);
    
    }
    
}

//wt_lb weight in pounds
//ht_in height in inches

float returnBMI(float wt_lb, float ht_in){

    return (703*wt_lb)/(ht_in*ht_in);

}
