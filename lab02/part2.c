#include <stdio.h>

/* ECE1120 - Lab 2 Part 1
 * by Parmvir Chahal
 */

int main(int argc, char *argv[])
{
    int x = 123456789;
    int y = 1000;
    
    /* This section displays and calculates the sum, product, integer quotient,
     * integer remainder and floating-point division quotient of the two integers x and y. */
    
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d * %d = %li\n", x, y, ((long int)x) * y);
    printf("%d // %d = %d\n", x, y, x / y);
    printf("%d %% %d = %d\n", x, y, x % y);
    printf("%d / %d = %f\n", x, y, ((float)x) / y);
    
    /* This program correctly calculates every single operation with the two integers
     * x and y, excluding the product. As the product is too big for the int data type,
     * the sign changes to - and then displays the value. In order to accomodate for the
     * larger value, the long int data type must be used. */
    
    return 0;
}