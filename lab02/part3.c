#include <stdio.h>

/* ECE1120 - Lab 2 Part 3
 * by Parmvir Chahal
 */

int main(int argc, char *argv[])
{
    char letter = 'C';
    
    /* This section displays the variable C as a character and as an integer. */
    
    printf("%c\n", letter);
    printf("%i\n", letter);

    letter = letter + 1;
    
    printf("%c\n", letter);
    printf("%i\n", letter);
    
    /* The program correctly displays the variable C as a character along with
     * its integer value. Once the integer 1 is added to the variable C, its value
     * as a character and an integer increases by 1. */
    
    return 0;
}