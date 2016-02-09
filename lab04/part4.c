#include <stdio.h>
#include <math.h>

/* ECE1120 - Lab 4 Part 4
 * by Parmvir Chahal
 */

/* This program reads an integer and prints its square root. It initially checks
 * if the integer that is input is positive or negative and exits the program if
 * it is the latter. If the integer is positive, the program calls the mysqrt
 * function. In mysqrt, epsilon is set to 0.00001 and guess is assigned to 1.0.
 * This function, however, calls another function, absolutevalue, to calculate
 * the absolute value of any input integer. In mysqrt, while the absolute value
 * of guess * guess – x (the originally input integer) is greater than epsilon,
 * guess is assigned to the value of the originally input integer divided by
 * guess + guess, all divided by 2.0. The program then assigns the value of guess
 * to root and prints the correct square root of the originally input integer.
 */

double absolutevalue(double y);

double mysqrt(double x);

int main ()
{
    double x, root;
    
    printf("Please type in a number.\n");
    
    scanf("%lf", &x);
    
    if ( x < 0)
    {
        printf("This is not a valid number.\n");
        return NAN;
    }
    
    root = mysqrt(x);
    
    printf("The square root of this number is %lf.\n", root);
    
    return 0;
}

double absolutevalue(double y)
{
    if (y < 0) {
        y = -y;
    }
    
    return y;
}

double mysqrt(double x)
{
    const double epsilon = 0.00001;
    double guess = 1.0;
    
    while (absolutevalue (guess * guess - x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
    }
    
    return guess;
}