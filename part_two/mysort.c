#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
static int debug = 0;

/* ECE1120 - Lab 9 Part 2
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

void printarray(const char *msg, char **A, int n)
{
	int i;
	
	printf("[ ");
	for (i = 0; i < n; i++) {
		printf("%s ", A[i]);
	}
	printf("]\n");
}

void merge(char **src, int left, int mid, int right, char **dst)
{
	int i = left, j = mid, k = left;

	while (i < mid && j < right)
	{
		if (strcmp(src[i], src[j]) < 0) {
			dst[k++] = src[i++];
		}
		else {
			dst[k++] = src[j++];
		}
	}

	while (j < right) {
		dst[k++] = src[j++];
	}

	while (i < mid) {
		dst[k++] = src[i++];
	}
}

#define MIN(a, b) (a < b ? a : b)

char **mergesort(char **A, unsigned int n)
{
	if (n < 2) {
		return A;
	}

	char **src = A;
	char **dst = calloc(n, sizeof(char*));

	if (!dst) {
		return NULL;
	}

	int w, i;
	for (w = 1; w < n; w *= 2) {
		if (debug) {
			printarray("src = ", src, n);
		}

		for (i = 0; i < n; i += 2*w) {
			int left = i;
			int mid = MIN(i + w, n);
			int right = MIN(i + 2*w, n);

			if (debug) {
				printf("w = %d merge i = %d to %d and %d to %d into %d\n", w, left, mid, mid, right, left);
			}

			merge(src, left, mid, right, dst);
		}

		if (debug) {
			printarray("dst = ", dst, n);
		}

		char **tmp = src;
		src = dst;
		dst = tmp;
	}

	if (src != A) {
		memcpy(A, src, n * sizeof(char*));
		free(src);
	}
	else {
		free(dst);
	}

	return A;
}

int main(int argc, char *argv[])
{
	int i, j;
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
	char **lineptr = calloc(1000000, sizeof(char*));

	for (i = 0; ; i++) {
		ssize_t rc = getline(&lineptr[i], &n, fp);

		if (rc < 0) {
			break;
		}
	}
	
	lineptr = mergesort(lineptr, i);
	
	for(j = 0; j < i; j++) {
		printf("%s", lineptr[j]);
	}

	free(lineptr);

	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		
		exit_status = 1;
	}

	fclose(fp);
	exit(exit_status);
}