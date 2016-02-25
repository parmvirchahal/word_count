#include <stdio.h>

/* ECE1120 - Lab 5 Part 2
 * by Parmvir Chahal
 */

/* This program reads in an integer and displays a table of values from i = 0 to
 * i = n, including the values for i, i ** 2, i ** 3, and i!*/

int x, i, j, k, fact, h;

int factorial(int x);

int main()
{
    printf("Please type in a number.\n");
    scanf("%i", &x);
    
    if ( x < 0) {
        printf("The number %i is not valid.\n", x);
    }
    
    else {
        for(i = 0; i <= x; i++) {
            j = i * i;
            k = j * i;
            fact = factorial(x);

            printf("%i %i %i %i\n", i, j, k, fact);
        }
        
        i = 0;
        while (i <= x) {
            j = i * i;
            k = j * i;
            fact = factorial(x);

            printf("%i %i %i %i\n", i, j, k, fact);
            
            i++;
        }
        
        i = 0;
        do {
            j = i * i;
            k = j * i;
            fact = factorial(x);

            printf("%i %i %i %i\n", i, j, k, fact);
            
            i++;
        } while (i <= x);
        
        
        i = 0;
        bad: if (i<=x) {
            j = i * i;
            k = j * i;
            fact = factorial(x);

            printf("%i %i %i %i\n", i, j, k, fact);
            
            i++;
            
            goto bad;
        }
    }
    
    return 0;
}

int factorial(int x)
{
    int h, fact = 1;
            for (h = 1; h <= i; h++) {
                fact = h * fact;
            }
    
    return fact;
}