//
//  main.c
//  AsciiTest
//
//  Created by Randy McMillan on 10/1/13.
//  Copyright (c) 2013 Randy McMillan. All rights reserved.
//
#include <stdio.h>
# include <string.h>
int main(int argc, const char * argv[])
{
    
    char r, x, y, z, w;
    printf("Enter x,y,z,w");
    scanf("%c%c%c%c", &x, &y, &z, &w);
    if (x < y)                r = x;
    else                r = y;
    if (r > z)                r = z;
    if (r > w)                r = w;
    printf("print - %c\n", r);
    
    return 0;
}