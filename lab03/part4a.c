#include <stdio.h>

/* ECE1120 - Lab 3 Part 4
 * by Parmvir Chahal
 */

/* This program reads in an integer and displays the sum of its digits. It
 * displays the sum of the digits of a postive integer as positive and the
 * sum of the digits of a negative integer as negative.
 */
 
int main(void)
{
    int x, y, sum;
    
    printf("Please type in a number.\n");
    scanf("%i", &x);
    
    while (x != 0) {
        y = x % 10;
        sum = y + sum;
        x = x / 10;
    }
        
    printf("%i\n", sum);
    
    return 0;
}