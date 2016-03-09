#include <stdio.h>
#include <string.h>

/* ECE1120 - Lab 6 Part 4
 * by Parmvir Chahal
 */

/* This program determines if one character string exists within another.*/

int string_compare(char *needle, char *haystack);
int find_string(char *needle, char *haystack);

int main() {
    int i= 0, z = 0;
    
    char y[256];
    char x[256];
    
    printf("Please enter the first string:\n");
    gets(y);
    
    printf("Please enter the string to be found from the first string:\n");
    gets(x);
    
    i = find_string(x, y);
    
    if (i == -1) {
        printf("The first string does not exist within the second string.\n");
        
        return 0;
    }
    
    else {
        printf("The first string exists within the second string.\n");
        
        z = strlen(y) - (i + strlen(x));
        
        printf("The difference of these two strings is %i.\n", z);
        
        return 0;
    }
}

int string_compare(char *needle, char *haystack) {  
    while (*needle == *haystack && *needle != '\0' && *haystack != '\0') {
        needle++;
        haystack++;
    }
    
    if (*needle == '\0') {
        
        return 0;
    }
    
    if (*haystack == '\0') {
        
        return -1;
    }

    return -1;
}

int find_string(char *needle, char *haystack) {
    int i = 0;
    
    while(string_compare(needle, haystack) && *haystack != '\0') {
        haystack++;
        i++;
    }
    
    if (*haystack == '\0') {
        
        return -1;
    }
    
    return i;
}