#include <stdio.h>
#include <stdbool.h>

/* ECE1120 - Lab 5 Part 4
 * by Parmvir Chahal
 */

/* This program reads in an integer and generates a table of prime numbers up to
 * that integer using trial division.*/

int main (void) {
    int p, x, i, primes[10000], primeIndex = 2; 
    bool isPrime;
    
    primes[0] = 2;
    primes[1] = 3;
    
    printf("Please type in the number up to which prime numbers are needed.\n");
    scanf("%i", &x);
    
    if (x > 10000) {
        printf("The number %i is too large.\n", x);
        
        return 0;
    }
    
    for ( p = 5; p <= x; p = p + 2 ) {
        isPrime = true;
        
        for ( i = 1; isPrime && p / primes[i] >= primes[i]; ++i )
            if ( p % primes[i] == 0 ) 
                isPrime = false;
            if ( isPrime == true ) {
                primes[primeIndex] = p;
                ++primeIndex;
            }
    }
    
    for ( i = 0; i < primeIndex; ++i )
        printf ("%i ", primes[i]);
        printf ("\n");
        
    return 0;
}