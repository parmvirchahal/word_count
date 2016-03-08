#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* ECE1120 - Lab 6 Part 1
 * by Parmvir Chahal
 */

/* This program finds the location and value of the largest and smallest elements
 * in an array.*/

void find_maximum(int A[], int n, int *idx_max, int *max_val);
void find_minimum(int A[], int n, int *idx_min, int *min_val);

int main(void)
{
    long int random(void);
    srandom(time(NULL));
    
    int i, A[10000], idx_max, max_val, idx_min, min_val;
    
    printf("The input array is [");
    for (i = 0; i < 10000; i++) {
        A[i] = random();
        printf("%i ", A[i]);
    }
    printf("].\n");
    
    find_maximum(A, 10000, &idx_max, &max_val);
    find_minimum(A, 10000, &idx_min, &min_val);
    
    printf("The location of the largest element is %i and its value is %i.\n", max_val, idx_max);
    printf("The location of the smallest element is %i and its value is %i.\n", min_val, idx_min);
    
    return 0;
}

void find_maximum(int A[], int n, int *idx_max, int *max_val) {
    int i;
    int max = INT_MIN;
    for (i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
            *max_val = (A[i]);
            *idx_max = i;
        }
    }
}

void find_minimum(int A[], int n, int *idx_min, int *min_val) {
    int i;
    int min = INT_MAX;
    for (i = 0; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            *min_val = (A[i]);
            *idx_min = i;
        }
    }
}