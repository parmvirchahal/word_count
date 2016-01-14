#include <stdio.h>

/* Hello world 
 * by Your Name Here.
 */

int main(int argc, char *argv[])
{
	printf("Hello world!\n");
	printf("Written by Parmvir Chahal\n");
	printf("\n");
	/* This section computes a sum. */
	int x, y, z;
	x = 10;
	y = 20;
	z = x + y;
	printf("The value of x is %d, the value of y is %d, which means z is %d.\n", x, y, z);
	printf("\n");
	/* This section solves a math problem. */
	int h, w, d, V;
	h = 11;
	w = 7;
	d = 14;
	V = h*w*d;
	printf("The height of a box is %d, the width is %d, the depth is %d, which means the volume is %d.\n", h, w, d, V);	
	return 0;
}
