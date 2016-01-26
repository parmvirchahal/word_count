#include <stdio.h>

/* ECE1120 - Lab 2 Part 1
 * by Parmvir Chahal
 */

int main(int argc, char *argv[])
{
    int x = 35;
    int y = 14;
    
    /* This section displays and calculates the sum, product, integer quotient,
     * integer remainder and floating-point division quotient of the two integers x and y. */
    
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d // %d = %d\n", x, y, x / y);
    printf("%d %% %d = %d\n", x, y, x % y);
    printf("%d / %d = %f\n", x, y, ((float)x) / y);
    
    /* I had to type cast the floating-point division quotient because the compiler
     * assumes that the quotient will be an integer unless it is specified otherwise. */
    
    return 0;
}