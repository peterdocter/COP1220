#ifndef GETOPT_H
#define GETOPT_H

/* implements UNIX-style getopt

	The example below shows typical usage.  The third argument is a string of
	option letters.  If an option letter is followed by ':' it takes an
	argument.  Getopt returns the option letter if it finds one; if the option
	specified is illegal, it prints an error message and returns '?'.  When
	no more options are found, it returns -1.  Optind always points to the
	next argument in the option list.  For options which take an argument,
	optarg points to the argument (see -c in the example).

	An option of "-" (single dash) signifies the end of the option list, and
	causes getopt to return -1.  This is useful for specifying filenames
	which start with a dash.

	This version of getopt recognizes options which begin with '-', but also
	recognizes '/' as an option switch (per NT usage).  Options which don't
	require an argument may be stacked on the command line.  Valid options
	using the example below:

		myprogram -a -b
		myprogram -ab
		myprogram -c file1 -ac file2
		myprogram -c:file

	As shown in the example, this version of getopt allows a ':' to be placed
	between the option letter and its argument.

EXAMPLE:

	#include <stdio.h>
	#include "getopt.h"
	main(int argc, char **argv)
	{
		int c;
		while ((c=getopt(argc, argv, "abc:")) != -1) {
			switch (c) {
			case 'a': printf("got -a\n"); break;
			case 'b': printf("got -b\n"); break;
			case 'c': printf("got -c = %s\n", optarg); break;
			case '?': printf(); exit(1);
			}
		}
		for ( ; optind < argc; optind++)
			process_file(argv[optind]);
	}

*/

int getopt(int argc, char ** argv, char *opt);

extern int   optind;	/* current argc index into arglist */
extern char *optarg;	/* argument string for options that take an argument */
extern int   opterr;	/* set to 1 if error condition, 0 otherwise; */
                        /* useful for using '?' as an option */

#endif
