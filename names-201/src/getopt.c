#include <stdio.h>
#include <string.h> /* strchr */
#include "getopt.h"

#define ERROR '?'
#define FINISHED -1

#define NIL  0
#define SWI  1
#define OPT  2
#define ARG  3
#define DONE 4

int optind = 1;
int opterr = 0;
char *optarg = "";

int getopt(int argc, char **argv, char *str)
{
	static int a=0;		/* index into argv[optind] */
	char *s;		/* index into str */
	static int opt=0;	/* are we currently looking at an option? */
	static int state=NIL;	/* current state */

	opterr=0;

	/* are we done? */
	if (optind >= argc) return FINISHED;

	/* end of current arg? */
	if (argv[optind][a]==0)
	{
		optind++; /* move on to next arg */
		if (optind >= argc) return FINISHED; /* nothing more to do */
		a=0;
		state=NIL;
	}

	optarg = argv[optind]; /* give it a default value */

	/* look for next option */
	/* starting a new argument? */
	if (a==0)
	{
		/* is it a switch? */
		if (argv[optind][a]=='-' || argv[optind][a]=='/')
		{
			a++;		/* next char */

			/* if optarg is a single "-", finished */
			if (argv[optind][a]==0)
			{
				optind++;
				return FINISHED;
			}
			state = OPT;	/* now processing an opt */
		}
		/* not switched, must be an arg */
		else return FINISHED;
	}
	else /* not a new argument */
	{
		if (state != OPT) { printf("state!=OPT\n"); return '?'; }
	}

	/* find the opt */
	s = strchr(str, argv[optind][a]);
	if (s == 0)
	{
		fprintf(stderr,"unknown option '%c'\n", argv[optind][a]);
		opterr=1;
		return ERROR;
	}
	a++;

	if (s[1]==':')
	{
		if (argv[optind][a]==':') 	/* allow  -o:str */
			a++;

		if (argv[optind][a]==0)		/* handle -o str */
		{
			optind++;
			if (optind >= argc)	/* oops, no optarg */
			{
				fprintf(stderr,"option '%c' requires an argument\n", *s);
				opterr=1;
				return ERROR;
			}
			a=0;
		}

		optarg = argv[optind]+a;	/* no longer in arg */
		optind++; 			/* advance to next arg */
		a=0;
		state = NIL;			/* reset state */
		return *s;
	}
	else return *s; /* got valid option */
}

