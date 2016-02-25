#include <stdio.h>

/* ECE1120 - Lab 5 Part 5
 * by Parmeir Chahal
 */

/* This program reads in an integer and prints ahether or not it is prime.*/

int i, a, b, c, d, e = 0;
int primes[10000];

int is_prime (int k);

int main(void)
{
    printf("Please type in an integer.\n");
    scanf("%d", &a);
    
    is_prime(a);
    
    return 0;
}

int is_prime (int k)
{
    for (i = 10000; i > 1; i--) {
        b = 0;
        
        for (c = i - 1; c > 1; c--) {
            if (i % c == 0) {
                b = 1;
            }
        }
        
        if (b == 0) {
            primes[e] = i;     
            e++;
        }
    }
    
    int prime = 0;
    
    for (d = 0; d <= 9999; d++)  {
        if (k == primes[d]) {
            prime = 1;
        }
    }
    
    if (prime == 1) {
        printf("1: This number is prime.\n");
    }
    
    else {
        printf("0: This number is not prime.\n");
    }
    
    return 0;
}

/* After testing larger array sizes, I found that the largest array size I can
 * use is 10000. If the size of the array increases to a value greater than this
 * number, the program does not finish running.*/