#include <stdio.h>

/* ECE1120 - Lab 2 Part 6
 * by Parmvir Chahal
 */

int main(void)
{

	int x, y;
	char c;

	printf("enter first number:\n");
	scanf("%d", &x);

	printf("enter second number:\n");
	scanf("%d", &y);

	printf("enter a character:\n");
	scanf("\n%c", &c);

    /* If an invalid integer is entered in the orginal program, then the porgram interprets
     * that value and all following values as nonexistent. However, it does interpret that
     * value as a character and recognizes that it is not one of the two specified characters.
     */

	if (c == '+') {
		printf("%d + %d is %d\n", x, y, x + y);
	}
	else if (c =='-') {
		printf("%d - %d is %d\n", x, y, x - y);
	}
	else if (c == '*') {
		printf("%d * %d is %d\n", x, y, x * y);
	}
	else if (c == '/') {
		printf("%d / %d is %f\n", x, y, ((float)x) / y);
	}	
	else if (c == '%') {
		printf("%d %% %d is %d\n", x, y, x % y);
	}
	else {
		printf("Unknown operator %c\n", c);
		return 1;
	}

	return 0;
}