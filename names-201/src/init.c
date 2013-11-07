/* Names v2.01 Copyright 1995 by Michael Harvey */

#include <stdlib.h>
#include <string.h>
#include <time.h>

/* declare global vars */
#define DECL_STATIC
#include "names.h"

void init()
{
	int i;

	/* initialize all counters */
	for (i=0; i<NONE; i++)
		siz[i]=0;

	/* randomize */
	srand(time(0));

	/* init output filename */
	strcpy(outfile,OUTFILE);
	isopen=0;
	outfp=NULL;
}

