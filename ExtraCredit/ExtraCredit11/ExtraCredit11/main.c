//
//  main.c
//  ExtraCredit11
//
//  Created by Randy McMillan on 11/2/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//

/*
 *
 *
 *   11. Write a function that will merge the contents of two sorted (ascending order) arrays of type double values, storing the result in an array output parameter (still in ascending order). The function should not assume that both its input parameter arrays are the same length but can assume that one array does not contain two copies of the same value. The result array should also contain no duplicate values.
 *   First array
 *   04
 *   Second array
 *   Result array
 *   Hint: When one of the input arrays has been exhausted, do not forget to copy the remaining data in the other array into the result array. Test your function with cases in which (1) the first array is exhausted first, (2) the second array is exhausted first, and (3) the two arrays are exhausted at the same time (i.e., they end with the same value). Remember that the arrays input to this func- tion must already be sorted.
 *
 *
 */

#include <stdio.h>

double	firstArray[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
double	secondArray[] = {-1.8, 3.1, 6.3};
double	thirdArray[100];
	int j = 0;

void sortAndMerge(double *fA, double *fB);

int main(int argc, const char *argv[])
{
	for (int i = 0; i != ((sizeof firstArray / sizeof *firstArray) | (sizeof secondArray / sizeof *secondArray)); i++) {

		printf("\nfirstArray[%i]  = %.2lf\n", i, firstArray[i]);
		printf("\nsecondArray[%i] = %.2lf\n", i, secondArray[i]);
		printf("\nthirdArray[%i] = %lf\n", i, thirdArray[i]);

		// double	firstArray[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
		// double	secondArray[] = {-1.8, 3.1, 6.3};

		if (firstArray[i] < secondArray[i]) {
			thirdArray[j] = firstArray[i];
			thirdArray[j] = secondArray[i];
		} else {
			thirdArray[j] = secondArray[i];
			thirdArray[j] = firstArray[i];
		}
        
        printf("\nfirstArray[%i]  = %.2lf\n", i, firstArray[i]);
		printf("\nsecondArray[%i] = %.2lf\n", i, secondArray[i]);
		printf("\nthirdArray[%i] = %lf\n", i, thirdArray[i]);
	}

	return 0;
}

void sortAndMerge(double *fA, double *fB) {}
