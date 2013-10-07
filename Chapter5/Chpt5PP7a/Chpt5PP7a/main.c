//
//  main.c
//  Chpt5PP7a
//
//  Created by Randy McMillan on 10/7/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 
 
 7. a.
 Write a program to process a collection of daily high temperatures. Your program should count and print the number of hot days (high tempera- ture 85 or higher), the number of pleasant days (high temperature 60–84), and the number of cold days (high temperatures less than 60). It should also display the category of each temperature. Test your program on the following data:
 55  62  68  74  59  45  41  58  60  67  65  78  82  88  91
 92  90  93  87  80  78  79  72  68  61  59
 
 
 */


#include <stdio.h>
#include <string.h>

#define HOT 85
#define PLEASANT 60
#define CATEGORY_HOT "Hot"
#define CATEGORY_PLEASANT "Pleasant"
#define CATEGORY_COLD "Cold"


void myMain();
void inputTemp();
void calculateCategory();
void printHotDays();
void printPleasantDays();
void printColdDays();

float temp;
int hot,pleasant,cold;


int main(int argc, const char * argv[])
{
    myMain();
    return 0;
}


void myMain(){

    inputTemp();
    calculateCategory();
    printHotDays();
    printPleasantDays();
    printColdDays();

}

void inputTemp(){

    printf("Please input a temperature --> ");
    scanf("%fl",&temp);
    

    char yesOrNo[100];
	printf("Would you like to input another temperature? y/n ");
	scanf("%s", yesOrNo);
    
	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		inputTemp();
	}
    
	if (strncmp(yesOrNo, "n", 2) == 0) {
		
        //printf("Good bye!");
        
        
        
    }

    
}
void calculateCategory(){}
void printHotDays(){}
void printPleasantDays(){}
void printColdDays(){}



