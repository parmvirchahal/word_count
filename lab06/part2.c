#include <stdio.h>

/* ECE1120 - Lab 6 Part 2
 * by Parmvir Chahal
 */

/* This program raises an integer to an integer power without using any of the
 * math library functions.*/

float x_to_the_n(int x, int n);

int main(void)
{
    float y, z;
    
    printf("Please type in the integer to be raised to an integer power: \n");
    scanf("%f", &y);
    
    printf("Please type in the power to raise the integer to: \n");
    scanf("%f", &z);
    
    float a = x_to_the_n(y, z);
    
    printf("%f raised to the power of %f is %f.\n", y, z, a);
    
    return 0;
}

float x_to_the_n(int x, int n) {
    float b = x, i;
    
    if (n > 0) {
        for (i = 1; i < n; i++) {
            x = x * b;
        }
        
        return x;
    }
    
    else if (n < 0) {
        n = -n;
        
        for (i = 1; i < n; i++) {
            x = x * b;
        }
        x = 1 / x;
        
        return x;
    }
    
    else {
        x = 1;
        
        return x;
    }
}