#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* ECE1120 - Lab 8 Part 2
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

int process_line(char *line, size_t n)
{
	int i = 0;
	int string_length = (n / sizeof(char));
	
	for (i = 0; i < string_length; i++) {
		line[i] = tolower(line[i]);
	}
	
	fputs(line, stdout);
	fflush(stdout);

	return 0;
}

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
	char *lineptr = 0;

	for (;;) {
		ssize_t rc = getline(&lineptr, &n, fp);

		if (rc < 0) {
			break;
		}

		if (rc > 0) {
			if (process_line(lineptr, rc) < 0) {
				exit_status = 1;
				free(lineptr);
				break;
			}
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