#include <stdio.h>

/* ECE1120 - Lab 6 Part 3
 * by Parmvir Chahal
 */

/* This program determines if one character string exists within another.*/

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct time elapsed_time (struct time time1, struct time time2);

int main (int argc, char *argv[]) {
    struct time initial, final, diff;
    
    printf("Please enter the initial time in 24-hour time: ");
    scanf("%d:%d:%d", &initial.hour, &initial.minutes, &initial.seconds);
    
    printf("Please enter the initial time in 24-hour time: ");
    scanf("%d:%d:%d", &final.hour, &final.minutes, &final.seconds);
    
    diff = elapsed_time(initial, final);
    
    printf("The difference between those times is %d:%d:%d.\n", diff.hour, diff.minutes, diff.seconds);
    
    return 0;
}

struct time elapsed_time (struct time time1, struct time time2) {
    struct time change;
    change.hour = time2.hour - time1.hour;
    change.minutes = time2.minutes - time1.minutes;
    change.seconds = time2.seconds - time1.seconds;
    
    if (change.seconds < 0) {
        change.seconds = (time2.seconds - time1.seconds) + 60;
        change.minutes = change.minutes - 1;
    }
    
    if (change.minutes < 0) {
        change.minutes = (time2.minutes - time1.minutes) + 59;
        change.hour = change.hour - 1;
    }
    
    if (change.hour < 0 && change.minutes != 0) {
        change.hour = (time2.hour - time1.hour) + 23;
    }
    else {
        change.hour = (time2.hour - time1.hour) + 24;
    }
    
    return change;
}