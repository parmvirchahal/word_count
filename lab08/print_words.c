#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* ECE1120 - Lab 8 Part 4
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

int process_line(char *line, size_t n)
{
	int i = 0, j = 0;
	int string_length = (n / sizeof(char));
	
	char a = 10;

	for (i = 0; i < string_length; i++) {
		while (isspace(line[i]) != 0 && isspace(line[i + 1]) != 0) {
			for (j = i; j < string_length; j++) {
				if (j == string_length - 1) {
					line[j] = ' ';
				}
				
				line[j] = line[j + 1];
			}
		}
		
		if (i != 0 && isspace(line[i]) != 0 && isalnum(line[i + 1]) != 0) {
			line[i] = a;
		}
	}
	
	if (isspace(line[0])) {
		for (i = 1; i < string_length; i++) {
			line[i - 1] = line[i];
		}
		
		line[string_length - 1] = ' ';
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