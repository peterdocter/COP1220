/* Names v2.01 Copyright 1995 by Michael Harvey */

#include <stdlib.h>
#include <string.h>

#ifdef MSDOS
#include "getopt.h"
#else
#include <getopt.h>
#endif

#include "names.h"

void init(void);
void names(void);

void version(void)
{
	printf("Names version %s\n",VERSION);
	puts(COPYRIGHT);
	puts("Permission granted for unrestricted noncommercial use.");
}

int main(int argc, char ** argv)
{
	FILE *f;
	int c,i,ok=0;
	int err=0, use=0;
	char path[200],*p,*s;

	ansi=1;
	caps=1;
	cvt=0;
	debug=0;
	forever=0;
	plurs=1;
	simple=0;

	init();

	while ((c = getopt(argc,argv,"acCdDf:Fhlpsv")) != -1)
	{
		switch(c)
		{
			case 'a':
				ansi=0;
				break;
			case 'c':
				caps=0;
				break;
			case 'C':
				caps=2;
				break;
			case 'd':
				debug++;
				ansi=0;
				break;
			case 'D':
				debug=99;
				ansi=0;
				break;
			case 'f':
				strcpy(outfile,optarg);
				break;
			case 'F':
				forever=1;
				break;
			case 'h':
				use++;
				break;
			case 'l':
				cvt=1;
				break;
			case 'p':
				plurs=0;
				break;
			case 's':
				simple=1;
				break;
			case 'v':
				version();
				return 0;
			default:
				err++;
				break;
		}
	}
	if (use || err)
	{
		printf("usage: %s [-acCdFhlpsv] [-f outfile] [infile...]\n", argv[0]);
		puts("  -a       suppress ansi control codes");
		puts("  -c       suppress capitalization");
		puts("  -C       force capitalization");
		puts("             (default is selective capitalization)");
		puts("  -d       debug (-D full debug)");
		printf("  -f file  specify output file, default \"%s\"\n",OUTFILE);
		puts("  -F       forever (default when reading from pipe)");
		puts("  -h       help");
		puts("  -l       convert all data to lowercase");
		puts("  -p       suppress pluralization");
		puts("  -s       simple output");
		puts("  -v       version info");
		return err;
	}

	/* read data files */
	if (optind==argc)
	{
		dprint("Reading from stdin:\n");
		readdata(stdin);
		forever=1;
	}
	else
	{
		p = getenv("ELE_DIR");
		if (p && *p) {
			for (s=p; *s; s++) ;
			--s;
		}

		while (optind < argc)
		{
			dprint("READING [%d] '%s'\n",optind,argv[optind]);

			strcpy(path,argv[optind]);
			if ((f = fopen(path,"r")) != NULL) goto okay;

			strcat(path,".ele");
			if ((f = fopen(path,"r")) != NULL) goto okay;

			if (!p) goto error;
			strcpy(path,p);
			if (*s != '/') strcat(path,"/");
			strcat(path,argv[optind]);
			if ((f = fopen(path,"r")) != NULL) goto okay;

			strcat(path,".ele");
			f = fopen(path,"r");

okay:
			if (f)
			{
				readdata(f);
				fclose(f);
			}
			else
error:				fprintf(stderr,"Unable to read %s\n",path);
			optind++;
		}
	}

	dprint5("DICTIONARY:\n");
	for (c=0; c<NONE; c++)
	{
		if (siz[c]) ok=1;

		dprint5("[%d] %d\n",c,siz[c]);
		for (i=0; i<siz[c]; i++)
		{
			dprint5("  data[%2d][%d]=\"%s\"\n", c,i,data[c][i]);
			if (strlen(data[c][i])==0)
				dprint("---------> data[%2d][%d]=\"%s\"\n",
					c,i,data[c][i]);
		}
	}

	if (ok) names();
	return 0;
}

