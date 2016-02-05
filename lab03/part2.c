#include <stdio.h>

/* ECE1120 - Lab 3 Part 2
 * by Parmvir Chahal
 */

/* This program reads in an integer and displays its digits in reverse, but in English. */

int main(void)
{
    int x, number;
    
    printf("Please type in a number.\n");
    scanf("%i", &x);
    
    if (x > 0) {
        do {
            number = x % 10;
            switch (number) {
                case 0:
                    printf ("zero ");
                    break;
                case 1:
                    printf ("one ");
                    break;
                case 2:
                    printf ("two ");
                    break;
                case 3:
                    printf ("three ");
                    break;
                case 4:
                    printf ("four ");
                    break;
                case 5:
                    printf ("five ");
                    break;
                case 6:
                    printf ("six ");
                    break;
                case 7:
                    printf ("seven ");
                    break;
                case 8:
                    printf ("eight ");
                    break;
                case 9:
                    printf ("nine ");
                    break;
            }
            
            x = x / 10;
        } while (x != 0);
        
        printf("\n");
    }
    
    else {
        x = -x;
        do {
            number = x % 10;
            switch (number) {
                case 0:
                    printf ("zero ");
                    break;
                case 1:
                    printf ("one ");
                    break;
                case 2:
                    printf ("two ");
                    break;
                case 3:
                    printf ("three ");
                    break;
                case 4:
                    printf ("four ");
                    break;
                case 5:
                    printf ("five ");
                    break;
                case 6:
                    printf ("six ");
                    break;
                case 7:
                    printf ("seven ");
                    break;
                case 8:
                    printf ("eight ");
                    break;
                case 9:
                    printf ("nine ");
                    break;
            }
            
            x = x / 10;
        } while (x != 0);
        
        printf("negative");
        printf ("\n");
    }
	return 0;
}