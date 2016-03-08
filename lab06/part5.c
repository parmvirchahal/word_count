#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ECE1120 - Lab 6 Part 5
 * by Parmvir Chahal
 */

/* This program computes a solution to a specific problem.*/

int simulation(int step);

int main(void)
{
    long int random(void);
    srandom(time(NULL));
    
    int i, x = 1, n = 10000;

    float success, failure, percent_success;
    
    for(i = 0; i < n; i++) {
        success += simulation(x);
    }
    
    failure = 10000 - success;
    
    percent_success = (success / 10000) * 100;
    
    printf("The number of sucesses is %f.\n", success);
    printf("The number of failures is %f.\n", failure);
    printf("The probability of success is %f.\n", percent_success);
    
    return 0;
}

int simulation(int step) {
    int value;
    
    step = 1;
    
    while (0 < step && step < 1000) {
        value = random() % 6 + 1;
        
        if (value < 3) {
            step = step - 1;
        }
        else {
            step++;
        }
    }
    
    if (step == 1000) {
        return 1;
    }
    
    return 0;
}