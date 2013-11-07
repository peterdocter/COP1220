#ifndef NAME_H
/* Names v2.01 Copyright 1995 by Michael Harvey */

#include <stdio.h>

#define VERSION "2.01"
#define COPYRIGHT "Copyright 1995 by Michael Harvey"
#define OUTFILE "names.out"

#ifdef DECL_STATIC
#define EXTERN /* */
#else
#define EXTERN extern
#endif

enum { PRE, MID, SUF, NOUN, NADJ, ADJ, NONE };

/* array sizes */
#define DATASIZ 2000

/* global variables */
EXTERN char * data[6][DATASIZ];			/* data arrays */
EXTERN int siz[6];				/* array sizes */
EXTERN char outfile[128];			/* output file */
EXTERN int isopen;				/* is the output file open? */
EXTERN FILE * outfp;				/* output file ptr */
EXTERN int ansi,caps,cvt,debug,plurs,simple;	/* flags */
EXTERN int forever;

/* declarations */
void init();
void readdata(FILE *);
void name();
void version();

#define dprint  if(debug) printf
#define dprint1 if(debug>1)printf
#define dprint2 if(debug>2)printf
#define dprint3 if(debug>3)printf
#define dprint4 if(debug>4)printf
#define dprint5 if(debug>5)printf
#define dprint6 if(debug>6)printf
#define dprint7 if(debug>7)printf
#define dprint8 if(debug>8)printf

#define NAME_H
#endif

