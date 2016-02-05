#include <stdio.h>

/* ECE1120 - Lab 3 Part 1
 * by Parmvir Chahal
 */

/* This program computes the GCD of two integers. */

int main(void)
{
    int x, y, number;
    
    printf("Please type in two positive numbers.\n");
    scanf("%i", &x);
    scanf("%i", &y);
    
    while ( y != 0 ) {
        number = x % y;
        x = y;
        y = number;
    }
    
    printf("Their greatest common divisor is %i.\n", x);
    
	return 0;
}