#include <stdio.h>

/* ECE1120 - Lab 3 Part 4
 * by Parmvir Chahal
 */

/* This program reads in an integer and displays the sum of its digits. It
 * displays the sum of the digits of both postive and negative integers as 
 * negative.
 */

int main(void)
{
    int x, y = 0, sum = 0;
    
    printf("Please type in a number.\n");
    scanf("%i", &x);
    
    if (x > 0) {
        do {
            y = x % 10;
            sum = y + sum;
            x = x / 10;
        } while (x != 0);
        
        printf("%i\n", sum);
    }
    
    else {
        x = -x;
        
        do {
            
            y = x % 10;
            sum = y + sum;
            x = x / 10;
        } while (x != 0);
        
        printf("%i\n", sum);
    }
    
	return 0;
}