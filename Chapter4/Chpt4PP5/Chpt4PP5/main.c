//
//  main.c
//  Chpt4PP5
//
//  Created by Randy McMillan on 9/30/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//


/*
 
 5. The National Earthquake Information Center has asked you to write a pro-
 gram implementing the following decision table to characterize an earthquake based on its Richter scale number.
 Richter Scale Number (n)   Characterization
 n < 5.0                    Little or no damage
 5.0 <= n <= 5.5            Some damage
 5.5 <= n < 6.5             Serious damage: walls may crack or fall
 6.5 <= n <= 7.5            Disaster: houses and buildings may collapse
 higher                     Catastrophe: most buildings destroyed
 
 
 ￼￼￼Could you handle this problem with a switch statement? If so, use a switch
 statement; if not, explain why.

 
 
 */
#include <stdio.h>
#include <string.h>

float n;
void inputRicterScaleNumber();
//
void outputCharacterization(float n);

void outputLittleOrNoDamage(float n);
void outputSomeDamage(float n);
void outputSeriousDamage(float n);
void outputDisaster(float n);
void outputCatastrophy(float n);
void outputSecondPart();


int main(int argc, const char * argv[]) {

    inputRicterScaleNumber();
    return 0;

}


void inputRicterScaleNumber(){
    
    printf("Please enter the Ricter Scale Number --> ");
    scanf("%f",&n);
    outputCharacterization(n);
    
}

void outputCharacterization(float n){

    if (n < 5.0) {
    
        outputLittleOrNoDamage(n);
    
    } else if (n >= 5.0 && n < 5.5){
    
        outputSomeDamage(n);
    
    } else if (n >= 5.5 && n < 6.5) {
    
        outputSeriousDamage(n);
    
    } else if (n >= 6.5 && n < 7.5) {
    
        outputDisaster(n);
    
    } else {
    
        outputCatastrophy(n);
        
    }

    
    char yesOrNo[100];
	printf("Would you like to calculate another? y/n ");
	scanf("%s", yesOrNo);
    
	if (strncmp(yesOrNo, "y", 2) == 0) {
		printf("\n");
		inputRicterScaleNumber();
	}
    
	if (strncmp(yesOrNo, "n", 2) == 0) {
		
        //printf("Good bye!");
	
        char yesOrNo[100];
        printf("Would you like to see the answer to the second part of the Assignment? y/n ");
        scanf("%s", yesOrNo);
        
        if (strncmp(yesOrNo, "y", 2) == 0) {
            printf("\n");
            outputSecondPart();
        }
        
        if (strncmp(yesOrNo, "n", 2) == 0) {
            
            printf("Good bye!");
        
        }

    
    }

    
};


void outputLittleOrNoDamage(float n){

    printf("Characterization for %.1lf - Little to no damage.\n",n);

}

void outputSomeDamage(float n){

    printf("Characterization for %.1lf - Some Damage\n",n);
    
}

void outputSeriousDamage(float n){

    printf("Characterization for %.1lf - Serious Damage: Walls may crack or fail\n",n);
    
}

void outputDisaster(float n){

    printf("Characterization for %.1lf - Disaster: houses and buildings may collapse\n",n);
    
}

void outputCatastrophy(float n){

    printf("Characterization for %.1lf - Catastrophy: most bukldings destroyed\n",n);
    
}

void outputSecondPart(){

//The second part of the Programming Project answer
    printf("In theory a programmer could program a switch to handle all possible Ricter scale numbers. I believe that it is much more prudent to use If/Then statements because it is easier to handle ranges of numbers. By using a statement like:\n\n 'if (n >= 5.0 && n < 5.5){ do someting here }' \n\na wide range of values are handled with much less coding.\n\n\n");

}