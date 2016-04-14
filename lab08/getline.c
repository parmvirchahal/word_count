#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* ECE1120 - Lab 8 Part 1
 * by Parmvir Chahal
 */

/* This program copies standard input to standard output, one line at a time,
 * using the getline() library function. This program was orginally written by
 * Professor Ahsen Uppal. */

int process_line(char *line, size_t n)
{
	/* Q10: What do the fputs and fflush functions do?
	 *0
	 * The fputs function writes the string s to stream, without its terminating
	 * null bytes.
	 * 
	 * The fflush function, for output streams, forces a write of all user-space
	 * buffered data for the given output or update sream via the stream's
	 * underlying write function. */
	 
	/* Q11: Why should we use them instead of printf or fprintf? 
	 * 
	 * The fputs and fflush functions simply write the strings supplied to them
	 * to the indicated output streams, without requiring formatting. These
	 * functions can print strings without parsing them, unlike the others. This
	 * also yields more memory that can be allocated. */
	
	/* Q12: What does the value of n represent? 
	 * 
	 * The value of n represents the number of bytes that the string occupies. */

	fputs(line, stdout);
	fflush(stdout);

	return 0;
}

int main(int argc, char *argv[])
{
	int exit_status = 0;
	FILE *fp;
	/* Q1: What values do argc and argv have when this program is run without any
	 * command-line parameters?
	 *
	 * The values of argc and argv are  and , respectively. */
	 
	/* Q2: What value do they have when run with a filename as an input argument?
	 *
	 * The vaules of argc and argv are  and , respectively. */
	
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");
		/* Q3: When is the condition !fp true, and when is it false?
		 * 
		 * */
		
		/* Q4: strerror() is called with the global variable errno that the C
		 * library maintains internally. What does strerror do?
		 * 
		 * */

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			/* Q5: What does the exit() library function do?
			 *
			 * */
			
			exit(1);
		}
	}

	size_t n = 0;
	char *lineptr = 0;
	/* Q6: What does a for(;;) loop do?
	 *
	 * The for(;;) loop */
	
	for (;;) {
		/* Q7: What is the difference between the types size_t and ssize_t ?
		 *
		 * The difference between size_t and ssize_t is */
		
		ssize_t rc = getline(&lineptr, &n, fp);
		/* Q8: What does the getline function do?
		 *
		 * The getline function */
		
		/* Q9: What does it return in the normal case, upon EOF, and upon error?
		 *
		 * */

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