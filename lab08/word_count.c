#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

/* ECE1120 - Lab 8 Part 5
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

struct word_count {
	int characters;
	int words;
	int lines;
};

int process_line(struct word_count* counts, char *line, size_t n)
{
	int i = 0;
	int string_length = (n / sizeof(char));
	
	counts->lines = counts->lines + 1;
	
	for (i = 0; i < string_length; i++) {
		counts->characters = counts->characters + 1;
	
		if (i != 0 && isspace(line[i]) != 0 && !isspace(line[i-1])){
			counts->words = counts->words + 1;
		}
	
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;
	
	struct word_count counts;
	
	counts.characters = 0;
	counts.words = 0;
	counts.lines = 0;
	
	
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
			if (process_line(&counts, lineptr, rc) < 0) {
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

	printf("The number of characters is %i.\n", counts.characters);
	printf("The number of words is %i.\n", counts.words);
	printf("The number of lines is %i.\n", counts.lines);

	fclose(fp);
	exit(exit_status);
}