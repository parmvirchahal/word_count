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
    
    /* This program incorrectly calculates the double a to be 0.000000, since it should
     * be 3.4E312. This error is a result of 
     */
    
    return 0;
}