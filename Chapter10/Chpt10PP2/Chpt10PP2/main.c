//
//  main.c
//  Chpt10PP2
//
//  Created by Randy McMillan on 11/21/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   2. Define a structure type element_t to represent one element from the peri- odic table of elements. Components should include the atomic number (an integer); the name, chemical symbol, and class (strings); a numeric field for the atomic weight; and a seven-element array of integers for the number of electrons in each shell. The following are the components of an element_t structure for sodium.
 *   11 Sodium Na alkali_metal 22.9898 2 8 1 0 0 0 0
 *   Define and test I/O functions scan_element and print_element.
 *
 *
 */

#include <stdio.h>
#define ZERO 0
#define LINE_LENGTH 10

struct {
	char	elementName[80];
	int		atmomicNum;
	char	chemicalSymbol[2];
	char	class[80];
	int		atomicWeight;
	int		shell1, shell2, shell3, shell4, shell5, shell6, shell7;
} element_t;

void myMain();

void getMembers();

char *scanString(char *dest, int dest_len);

int *scanInt(int *dest, int dest_len);

void enterElementName();

void enterAtomicNumber();

void enterChemicalSymbol();

void enterClass();

void enterAtomicWeight();

void enterShellOne();

void enterShellTwo();

void enterShellThree();

void enterShellFour();

void enterShellFive();

void enterShellSix();

void enterShellSeven();

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	getMembers();
}

void getMembers()
{
	enterElementName();

	enterAtomicNumber();

	enterChemicalSymbol();

	enterClass();

	enterAtomicWeight();

	enterShellOne();

	enterShellTwo();

	enterShellThree();

	enterShellFour();

	enterShellFive();

	enterShellSix();

	enterShellSeven();
}

void enterElementName() {

    scanString(element_t.elementName, LINE_LENGTH);
    printf("The element Name is - %s\n",element_t.elementName);
    
}

void enterAtomicNumber() {

    scanInt(&element_t.atmomicNum, LINE_LENGTH);
    printf("The Atomic Number is - %u\n",element_t.atmomicNum);


}

void enterChemicalSymbol() {

    scanString(element_t.elementName, LINE_LENGTH);
    scanString(element_t.chemicalSymbol, LINE_LENGTH);
    printf("The Chemical Symbol is - %s\n",element_t.chemicalSymbol);
    

}

void enterClass() {}

void enterAtomicWeight() {}

void enterShellOne() {}

void enterShellTwo() {}

void enterShellThree() {}

void enterShellFour() {}

void enterShellFive() {}

void enterShellSix() {}

void enterShellSeven() {}



// Based on Figure 8.15 in Book
char *scanString(char *dest, int dest_len)
{
	int i, ch;

	i = ZERO;

	for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar()) {
		dest[i++] = ch;
	}

	dest[i] = '\0';

	while (ch != '\n' && ch != EOF) {
		ch = getchar();
	}

	return dest;
}

// Based on Figure 8.15 in Book
int *scanInt(int *dest, int dest_len)
{
    scanf("\n%i", dest);
	return dest;
}

