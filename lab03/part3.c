#include <stdio.h>

/* ECE1120 - Lab 3 Part 3
 * by Parmvir Chahal
 */

/* This program reads in an integer and displays a table of values from i = 0 to i = n,
 * including the values for i, i ** 2, i ** 3, and i!*/

int main(void)
{
    int x, i, j, k, factorial, h;
    
    printf("Please type in a number.\n");
    scanf("%i", &x);
    
    if ( x < 0) {
        printf("This number is not valid.\n");
    }
    
    else {
        for(i = 0; i <= x; i++) {
            j = i * i;
            k = j * i;
            factorial = 1;
            for (h = 1; h <= i; h++) {
                factorial = h * factorial;
            }

            printf("%i %i %i %i\n", i, j, k, factorial);
        }
    }
    
    return 0;
}