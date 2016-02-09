#include <stdio.h>

/* ECE1120 - Lab 4 Part 1
 * by Parmvir Chahal
 */

/* This program computes the GCD of two integers. The two integers that are
 * initially input into the program are stored without being modified. After
 * this program calls the gcd function, the first integer becomes the GCD and
 * the second integer becomes the remainder that is output when the first
 * integer is divided by the second. After the function call is complete, the
 * values of the two integers are unchanged. This program prints the GCD of
 * the two integers before exiting.
 */

int gcd(int a, int b);

int main()
{
    int u, v, number;
    
    printf("Please type in two positive numbers.\n");
    
    scanf("%i\n %i", &u, &v);
    
    printf("The entered integers are %i and %i.\n", u, v);
    
    number = gcd(u, v);
    
    printf("The entered integers are finally %i and %i.\n", u, v);
    
    printf("Their greatest common divisor is %i.\n", number);
    
    return 0;
}

int gcd(int a, int b)
{
    int gcd;
    
    while ( b != 0 ) {
        gcd = a % b;
        a = b;
        b = gcd;
    }
    
    printf("The entered integers become %i and %i.\n", a, b);
    
	return a;
}