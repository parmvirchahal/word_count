#include <stdio.h>

/* ECE1120 - Lab 5 Part 3
 * by Parmvir Chahal
 */

/* This program reads in an integer and a base to convert that integer to and
 * prints the integer converted to that base.*/

const char baseDigits[16] = { 
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; 
char printable_digits[64]; 
long int x; 
int nextDigit, base, myIndex = 0;

int convert_base(long int x, int base, char printable_digits[myIndex]);

int main () 
{
    printf ("Please type in the number to be converted: ");
    scanf ("%li", &x); 
    printf ("Please type in the base to convert the number to: "); 
    scanf ("%i", &base);

    convert_base(x, base, printable_digits);

    return 0;
}

int convert_base(long int x, int base, char printable_digits[myIndex])
{
    if (x < 0) {
        printf("The number %li is not valid.\n", x);
        
        return -1;
    }
    
    else if (base < 0) {
        printf("The base %i is not valid.\n", base);
    
        return -1;
    }
    
    else {
        do {
            printable_digits[myIndex] = x % base;
            ++myIndex;
            x = x / base;
        } while ( x != 0 );
    }
    
    printf ("The converted number is "); 
    
    for (--myIndex; myIndex >= 0; --myIndex ) {
        nextDigit = printable_digits[myIndex]; 
        printf ("%c", baseDigits[nextDigit]);
    }
    
    printf (".\n");
    
    return 0;
}

/* In this program, I have set both a negative input integer and a negative
 * base as errors. Although it is mathematically possible to convert negative
 * integers to different bases and convert integers to negative bases, making
 * those conversions in this program returns an incorrect new integer. As a
 * result, I used an if statement to check for negative integers and negative
 * bases, which prevents the program from running and returns -1 if those
 * values are entered.*/