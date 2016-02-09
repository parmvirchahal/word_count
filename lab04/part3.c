#include <stdio.h>

/* ECE1120 - Lab 4 Part 3
 * by Parmvir Chahal
 */

/* This program computes the sum of all the elements in an array. */

long array_sum(int A[], unsigned int n);

int main ()
{
    int x[1000];
    int n;
    int i;
    int sum;

    printf("Please type in the number of elements in the array.\n");
    scanf("%i", &n);
    
    if (n > 1000) 
    {
        printf("This number is too large.\n");
        return 0;
    }
    
    for (i = 0; i < n; i++)
    {
        printf("Enter the %i number.\n", i);
        scanf("%i", &x[i]);
    }
    
    sum = array_sum(x, n);
    
    printf("The sum  of the elements in this array is %i.\n", sum);
    
    return 0;
}

long array_sum(int A[], unsigned int n)
{
    int x, sum = 0;
    
    for (x = 0; x < n; x++)
    {
        sum = sum + A[x];
    }
    
    return sum;
}