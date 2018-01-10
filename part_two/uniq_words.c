#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* ECE1120 - Lab 9 Part 1
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;
	
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));

			exit(1);
		}
	}

	size_t n = 0;
	char *lineptr;
	
	int count;
	char *pre_line = 0;
 	
	for (;;) {
		ssize_t rc = getline(&lineptr, &n, fp);

		if (pre_line == NULL) {
			count = 1;
			pre_line = strdup(lineptr);
		}
		
		else {
			if (strcmp(pre_line, lineptr) == 0) {
				count = count + 1;
			}
			else {
				printf("%12i\t%s", count, pre_line);
			
				count = 1;
				pre_line = strdup(lineptr);
			}
		}

		if (rc < 0) {
			break;
		}

		free(lineptr);
		
		lineptr = 0;
		n = 0;
	}

	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		
		exit_status = 1;
	}

	fclose(fp);
	exit(exit_status);
}