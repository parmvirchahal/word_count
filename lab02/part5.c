#include <stdio.h>

/* ECE1120 - Lab 2 Part 5
 * by Parmvir Chahal
 */

int main(void)
{
    /* This section displays the double number and the double number * 10000.0. */
    
    double number = 3.4E307;
    
    printf("number is %e\n", number);
    
    number = number * 10000.0;
    
    printf("number multiplied by 10000 is %e\n", number);
    
    /* This program incorrectly calculates the double number to be inf, since it should
     * be 3.4E312. This error is a result of an issue of precision because the double
     * data type is not large enough to store the 10000.0 that is multipled to 3.4e307.
     * As a result, the program simply displays inf to indicate that the boundaries of
     * the double data type have been reached.
     */
    
    return 0;
}