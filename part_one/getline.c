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
	 *
	 * The fputs function writes a string to the specified stream up to but not
	 * including the null character.
	 * 
	 * The fflush function flushes the output buffer of a stream. */
	 
	/* Q11: Why should we use them instead of printf or fprintf? 
	 * 
	 * The fputs and fflush functions simply write the strings supplied to them
	 * to the indicated output streams, without editing formatting. As a rsult,
	 * these functions can print strings without parsing them, unlike printf or
	 * fprintf. This also yields more empty memory that can be allocated. */
	
	/* Q12: What does the value of n represent? 
	 * 
	 * The value of n represents the size of the input string, because size_t
	 * is a data type primarily used for that purpose. */

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
	 * The values of argc and argv are  1 and 1, respectively. */
	 
	/* Q2: What value do they have when run with a filename as an input argument?
	 *
	 * The vaule of argc is 2 and the values of argv include both the command
	 * used to run this program and the file that is the input argument. */
	
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");
		/* Q3: When is the condition !fp true, and when is it false?
		 * 
		 * The condition !fp is true when there isn't an input stream available
		 * and it is false when there is an input stream available. */
		
		/* Q4: strerror() is called with the global variable errno that the C
		 * library maintains internally. What does strerror do?
		 * 
		 * The strerror function returns a string that descrbies the appropriate
		 * error code, or an unknown error message if the error code cannot be
		 * identified. */

		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			/* Q5: What does the exit() library function do?
			 *
			 * The exit function immediately terminates the calling process. In
			 * addition, any children of the process are terminated as well. */
			
			exit(1);
		}
	}

	size_t n = 0;
	char *lineptr = 0;
	/* Q6: What does a for(;;) loop do?
	 *
	 * The for(;;) loop runs infinitely. */
	
	for (;;) {
		/* Q7: What is the difference between the types size_t and ssize_t ?
		 *
		 * The difference between size_t and ssize_t is that while size_t is
		 * is an unsigned data type, ssize_t must be a signed data type. */
		
		ssize_t rc = getline(&lineptr, &n, fp);
		/* Q8: What does the getline function do?
		 *
		 * The getline function reads an input stream, one line at a time, up to
		 * and including the next newline character.*/
		
		/* Q9: What does it return in the normal case, upon EOF, and upon error?
		 *
		 * In normal cases, the getline function returns the number of
		 * characters it has read. Otherwise, in the case of EOF anf errors, it
		 * will return -1. */

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