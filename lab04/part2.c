#include <stdio.h>

/* ECE1120 - Lab 4 Part 2
 * by Parmvir Chahal
 */

/* This program reads an integer and prints it in decimal notation. */

void print_int(int x);

int main (void)
{
    int x;
    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    printf("Please type in the number to be converted.\n");
    
    scanf("%i", &x);
    
    print_int(x);
    
    return 0;
}

void print_int(int x)
{
    
}