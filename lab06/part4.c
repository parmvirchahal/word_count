#include <stdio.h>

/* ECE1120 - Lab 6 Part 4
 * by Parmvir Chahal
 */

/* This program determines if one character string exists within another.*/

int string_compare(char *needle, char *haystack);
int find_string(char *needle, char *haystack);

int main() {
    char y[256];
    char x[256];
    
    printf("Please enter the first string:\n");
    scanf("%s", y);
    
    printf("Please enter the string to be found from the first string:\n");
    scanf("%s", x);
    
    find_string(x, y);
    string_compare(x, y);
    
    return 0;
}

int string_compare(char *needle, char *haystack) {  
    while (*needle == *haystack && *needle != '\0' && *haystack != '\0') {
        needle++;
        haystack++;
    }
    
    if (*needle == '\0') {
        printf("The string '%s' exists within the string '%s'.\n", needle, haystack);
        
        return 0;
    }
    if (*haystack == '\0') {
        printf("The string '%s' does not exist within the string '%s'.\n", needle, haystack);
        
        return -1;
    }

    return -1;
}

int find_string(char *needle, char *haystack) {
    while(string_compare(needle, haystack) && *haystack != '\0') {
        haystack++;
    }
    
    return 0;
}