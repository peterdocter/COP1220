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
#define ZERO		0
#define LINE_LENGTH 80

char resetString;

struct {
	char	elementName[80];
	int		atomicNum;
	char	chemicalSymbol[80];
	char	class[80];
	double		atomicWeight;
	int		shell[7];
} element_t;

void myMain();

void scan_element();

char *scanString(char *dest, int dest_len);

int *scanInt(int *dest, int dest_len);

double *scanDouble(double *dest, int dest_len);

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

void print_element();

int main(int argc, const char *argv[])
{
	myMain();
	return 0;
}

void myMain()
{
	scan_element();
}

void scan_element()
{
	enterElementName();
	enterChemicalSymbol();
	enterClass();
	//
	//
	enterAtomicNumber();
	enterAtomicWeight();
	//
	//
	enterShellOne();
	enterShellTwo();
	enterShellThree();
	enterShellFour();
	enterShellFive();
	enterShellSix();
	enterShellSeven();
	//
	//
	print_element();
}

void enterElementName()
{
	printf("Please enter the Element Name ---> ");
	scanString(element_t.elementName, LINE_LENGTH);
}

void enterChemicalSymbol()
{
	printf("Please enter the Chemical Symbol for %s ---> ", element_t.elementName);
	scanString(element_t.chemicalSymbol, LINE_LENGTH);
}

void enterClass()
{
	printf("Please enter the Element Class ---> ");
	scanString(element_t.class, LINE_LENGTH);
}

void enterAtomicNumber()
{
	printf("Please enter the Atomic Number ---> ");
    //	scanInt(&element_t.atomicNum, LINE_LENGTH);
   	scanInt(&element_t.atomicNum, LINE_LENGTH);
}

void enterAtomicWeight()
{
	printf("Please enter the Atomic Weight ---> ");
	scanDouble(&element_t.atomicWeight, LINE_LENGTH);
}

void enterShellOne()
{
	printf("Please enter the Shell One ---> ");
	scanInt(&element_t.shell[0], LINE_LENGTH);
}

void enterShellTwo()
{
	printf("Please enter the Shell Two ---> ");
	scanInt(&element_t.shell[1], LINE_LENGTH);
}

void enterShellThree()
{
	printf("Please enter the Shell Three ---> ");
	scanInt(&element_t.shell[2], LINE_LENGTH);
}

void enterShellFour()
{
	printf("Please enter the Shell Four ---> ");
	scanInt(&element_t.shell[3], LINE_LENGTH);
}

void enterShellFive()
{
	printf("Please enter the Shell Five ---> ");
	scanInt(&element_t.shell[4], LINE_LENGTH);
}

void enterShellSix()
{
	printf("Please enter the Shell Six ---> ");
	scanInt(&element_t.shell[5], LINE_LENGTH);
}

void enterShellSeven()
{
	printf("Please enter the Shell Seven ---> ");
	scanInt(&element_t.shell[6], LINE_LENGTH);
}

void print_element()
{
	// 11 Sodium Na alkali_metal 22.9898 2 8 1 0 0 0 0
	printf("\n%i %s %s %.80s %.4lf %i %i %i %i %i %i %i\n", element_t.atomicNum, element_t.elementName, element_t.chemicalSymbol, element_t.class, element_t.atomicWeight, element_t.shell[0], element_t.shell[1], element_t.shell[2], element_t.shell[3], element_t.shell[4], element_t.shell[5], element_t.shell[6]);
}

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

int *scanInt(int *dest, int dest_len)
{
	scanf("\n%i", dest);
	return dest;
}

double *scanDouble(double *dest, int dest_len)
{
	scanf("\n%lf", dest);
	return dest;
}
