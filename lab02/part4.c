#include <stdio.h>

/* ECE1120 - Lab 2 Part 4
 * by Parmvir Chahal
 */

int main(void)
{
    
    /* This section displays the double a, which depends on the value of the double b. */
    
    double a, b;
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    
    printf("%f\n", a);
    
    /* This program incorrectly calculates the double a to be 0.000000, since it should
     * be 1.000000. This error is a result of an issue of precision because the double
     * data type is not large enough to store the 1.0 that is added to 2.0e20. As a
     * result, the program truncates the value of the double b and calculates the value
     * of the double a to be 0.
     */
    
    return 0;
}