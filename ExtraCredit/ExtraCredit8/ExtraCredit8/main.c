//
//  main.c
//  ExtraCredit8
//
//  Created by Randy McMillan on 11/2/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *   8. Write a program to process weekly employee time cards for all employees of an organization. Each employee will have three data items: an identification number, the hourly wage rate, and the number of hours worked during a given week. Each employee is to be paid time and a half for all hours worked over 40. A tax amount of 3.625% of gross salary will be deducted. The program out- put should show the employee’s number and net pay. Display the total payroll and the average amount paid at the end of the run.
 *
 */

#include <stdio.h>
#include <string.h>

#define FORTY	40
#define TAX		3.625
#define ZERO	0
#define LINE	80

int		e;
int		numberOfEmployees;
int		idNum[];
float	hourlyRate[];
float	hoursWorked[];
char	firstName[], lastName[];
char	input[LINE];
void	inputEmployee();

void myMain();

void inputNumberOfEmployees();

char *scanLine(char *dest, int dest_len);

void assignFirstName(char *input, int loopLength);

int main(int argc, const char *argv[])
{
	myMain();

	return 0;
}

void myMain()
{
	inputNumberOfEmployees();
	inputEmployee();
}

void inputEmployee()
{
	e = e + 1;

	for (int i = 0; i < numberOfEmployees; i++) {
		//

		printf("Please enter the Employees first name --> ");
		assignFirstName(scanLine(input, LINE), (int)strlen(input) + 1);
		
        scanLine(input,LINE);
        
        assignFirstName(input, (int)strlen(input)-1);
        
        //scanLine(input, LINE);
		//strcpy(&firstName[i], input);
		//printf("%s", &firstName[i]);
        
        
        
        
	}
}

void inputNumberOfEmployees()
{
	printf("Plese enter the number of employees --> ");
	scanf("%i", &numberOfEmployees);
}

void assignFirstName(char *input, int loopLength) {

    //printf("%s",input);


}

// Based on Figure 8.15 in Book
char *scanLine(char *dest, int dest_len)
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
