#include <stdio.h>

/* ECE1120 - Lab 5 Part 1
 * by Parmvir Chahal
 */

/* This program reads an integer and prints that amount of Fibonacci numbers.*/

int x;

int fibonacci(int n);

int main (void) 
{
    printf("Please type in the desired amount of Fibonacci numbers.\n");
    scanf("%i", &x);
    
    printf("The first %i Fibonacci numbers are:\n", x);
    
    fibonacci(x);
    
    return 0;
}

int fibonacci(int n) {
    int i = 0;
    int Fibonacci[n];
    Fibonacci[0] = 1;
    Fibonacci[1] = 1;

    
    for ( i = 2; i < n; ++i ) {
        Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1]; 
    }    
    
    for ( i = 0; i < n; ++i ) {
        printf ("Fibonacci[%i] = %i\n", i, Fibonacci[i]);
    }
    
    return 0;
}