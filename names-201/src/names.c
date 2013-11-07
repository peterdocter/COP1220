/* Names v2.01 Copyright 1995 by Michael Harvey */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "names.h"
#include "keyb.h"

void clear(void);
void version(void);
void gen(void);
void display(void);
void helpscr(void);

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define LINES 20
#define COLUMNS 2
#define BUFLEN 40

#define SAVED ' '
#define ready() move(21,1)

#ifdef UNIX
#define getkey() getchar()
#endif

#ifdef TURBOC
#include <conio.h>
#define getkey() getch()
#define kb_init() /**/
#define kb_wait() /**/
#define kb_done() /**/

#define clear() clrscr()
#define move(y,x) gotoxy(x,y)
#endif

enum { O_PS, O_PMS, O_N, O_X, O_NA, O_XA, O_NX };

char scr[LINES][COLUMNS][BUFLEN];
int saved[LINES][COLUMNS];

char buf1[80];
char buf2[80];

#ifndef TURBOC
void clear()
{
	if (ansi) printf("\033c");
	else putchar('\n');
}

void move(int y, int x)
{
	if (ansi) printf("\033[%d;%df",y,x);
}
#endif

void helpscr()
{
	clear();
	version();
	puts("\nPress SPACE to generate a screenful of names.");
	puts("Individual names can be saved to the output file by pressing");
	puts("the appropriate key.  ENTER quits the program.");
	puts("\nOther commands:\n");
	puts("   !  invoke a shell");
	puts("   ?  this help screen");
	getkey();
}

char * cap(char *buf) /* capitalize one word */
{
	char *p;
	if (caps==1)
	{
		dprint2("cap(%s)",buf);
		p=buf;
		while (*p==' ') p++;

		if (*p >= 'a' && *p <= 'z')
			*p -= ('a' - 'A');
		dprint2("=\"%s\"\n",buf);
	}
	if (strlen(buf)==0) dprint("==========> cap() buf=\"%s\"\n",buf);
	return buf;
}

void cap2(char *buf)  /* capitalize everything in buffer */
{
	char *p;
	int newword=1;

	for (p=buf; *p; p++)
	{
		if (*p==' ')
			newword=1;
		else if (newword) /* capitalize */
		{
			if (*p >= 'a' && *p <= 'z')
				*p -= ('a' - 'A');
			newword=0;
		}
		/* else ignore */
	}
}

char * plur(char *buf)
{
	char *p;

	if (!plurs) return buf;
	dprint2("plur(%s)",buf);

	for (p=buf; *p; p++) ;	/* find end of string */
	p--;			/* find last char */

	if (*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u') {
		strcat(buf,"s");
	} else if (*p=='y') {
		p--;
		if (*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u') {
			strcat(buf,"s");
		} else {
			p++;
			*p=0;
			strcat(buf,"ies");
		}
	} else if (*p=='s') {
		p--;
		if (*p=='s') strcat(buf,"es");
	} else if (*p=='h') {
		p--;
		if (*p=='t' || *p=='s' || *p=='c' || *p=='r' || *p=='z')
			strcat(buf,"es");
		else strcat(buf,"s");
	}else if (*p=='f') {
		p-=2;

		if (strncmp(p,"aff",3)==0)
			strcpy(p,"aves");
		else if (strncmp(p,"arf",3)==0)
			strcpy(p,"arves"); /* or "arrows" */
		else if (strncmp(p,"elf",3)==0)
			strcpy(p,"elves");
	} else if (*p!='c' && *p!='j' && *p!='v' && *p!='x' && *p!='z')
		strcat(buf,"s");

	dprint2("=\"%s\"\n",buf);
	if (strlen(buf)==0) dprint("==========> plur() buf=\"%s\"\n",buf);
	return buf;
}

int rnd(int n)
{
	if (n<=0)
	{
		dprint("error: rnd(0)\n");
		return 0;
	}
	return (rand() % n);
}

char * names_select(int n)
{
	int i;
	char *p;

	if (n>=NONE) dprint("error:  n==NONE\n");

	i = rnd(siz[n]);

	if (i<0 || i>=siz[n])
	{
		dprint("error:  i==%d siz[%d]==%d\n",i,siz[n],n);
		i=0;
	}
	p = data[n][i];

	if (strlen(p)==0)
	{
		dprint("###### data[%2d][%d] = \"%s\"\n",n,i,p);
	}

	if (p==NULL)
	{
		dprint("error:  data[%d][%d]==NULL\n",n,i);
		p="ERR";
	}
	dprint1("names_select(%d): data[%d][%d]='%s'\n",n,n,i,p);
	return p;
}

char * number(char *buf, char *n1)
{
	switch(rnd(16))
	{
		case  0: sprintf(buf,"No %s",plur(n1)); break;
		case  1: sprintf(buf,"One %s",n1); break;
		case  2: sprintf(buf,"Two %s",plur(n1)); break;
		case  3: sprintf(buf,"Three %s",plur(n1)); break;
		case  4: sprintf(buf,"Four %s",plur(n1)); break;
		case  5: sprintf(buf,"Five %s",plur(n1)); break;
		case  6: sprintf(buf,"Six %s",plur(n1)); break;
		case  7: sprintf(buf,"Seven %s",plur(n1)); break;
		case  8: sprintf(buf,"Eight %s",plur(n1)); break;
		case  9: sprintf(buf,"Nine %s",plur(n1)); break;
		case 10: sprintf(buf,"Ten %s",plur(n1)); break;
		case 11: sprintf(buf,"Eleven %s",plur(n1)); break;
		case 12: sprintf(buf,"Twelve %s",plur(n1)); break;

		case 13: sprintf(buf,"Hundred %s",plur(n1)); break;
		case 14: sprintf(buf,"Lone %s",n1); break;
		case 15: sprintf(buf,"Many %s",plur(n1)); break;
	}
	if (strlen(buf)==0) dprint("==========> number() buf=\"%s\"\n",buf);
	return buf;
}

void type1(char *buf, char *n1, char *n2) /* noun / noun */
{
	char *fmt;
	int i;

	if (simple) i = 0;
	else i = rnd(5);

	switch(i)
	{
		case 0: sprintf(buf,"%s%s",cap(n1),n2);
			dprint2("(nn)");
			break;
		case 1: sprintf(buf,"%s and %s",cap(n1), cap(n2));
			switch (rnd(2)) {
				case 0: strcat(buf," Inn"); break;
				case 1: strcat(buf," Tavern"); break;
			}
			dprint2("(n and n x)");
			break;
		case 2: if (rnd(2)) {
				sprintf(buf,"%s of %s",plur(cap(n1)),cap(n2));
				dprint2("(ns of n)");
			} else {
				sprintf(buf,"%s of %s",cap(n1),plur(cap(n2)));
				dprint2("(n of ns)");
			} break;
		case 3: switch(rnd(3)) {
			case 0:
				sprintf(buf,"%s of the %s",cap(n1),plur(cap(n2)));
				dprint2("(n of the ns)");
				break;
			case 1:
				sprintf(buf,"%s of the %s",plur(cap(n1)),cap(n2));
				dprint2("(ns of the n)");
				break;
			case 2: sprintf(buf,"%s of the %s",plur(cap(n1)),plur(cap(n2)));
				dprint2("(ns of the ns)");
				break;
			} break;
		case 4: number(buf,cap(n1));
			switch(rnd(5)) {
				case 2: strcat(buf," Inn"); break;
				case 3: strcat(buf," Harbor"); break;
				case 4: strcat(buf," Tower"); break;
			}
			dprint2("(# ns [x])");
			break;
	}
	if (strlen(buf)==0) dprint("==========> type1() buf=\"%s\"\n",buf);
}

void type2(char *buf, char *n, char *a) /* noun / adj */
{
	char *fmt;
	int i;
	char tmp[80];

	if (simple) i = rnd(2);
	else i = rnd(4);

	switch(i)
	{
		case 0: sprintf(buf,"%s%s",a,n);
			dprint2("(na)");
			cap(buf);
			break;
		case 1: sprintf(buf,"%s %s",a,n);
			dprint2("(n a)");
			cap(buf);
			break;
		case 2: sprintf(buf,"%s %s",cap(a),cap(n));
			dprint2("(n a [x])");
			#ifdef NEVER
			switch (rnd(6)) {
				/* 0,1,2 leave as is */
				case 3: strcat(buf," Inn"); break;
				case 4: strcat(buf," Town"); break;
				case 5: strcat(buf," Tower"); break;
			}
			#endif
			break;
		case 3: sprintf(tmp,"%s %s",cap(a), cap(n));
			number(buf,tmp);
			dprint2("(# a ns)");
			break;
	}
	if (strlen(buf)==0) dprint("==========> type2() buf=\"%s\"\n",buf);
}


void newname(char *buf)
{
	int option[10], opt;
	int numopt=0;
	char *noun, *adj;

	if (siz[PRE] && siz[SUF])		option[numopt++]=O_PS;
	if (siz[PRE] && siz[MID] && siz[SUF])	option[numopt++]=O_PMS;
	if (siz[NOUN])				option[numopt++]=O_N;
	if (siz[NADJ])				option[numopt++]=O_X;
	if (siz[NOUN] && siz[ADJ])		option[numopt++]=O_NA;
	if (siz[NOUN] && siz[NADJ])		option[numopt++]=O_NX;
	if (siz[NADJ] && siz[ADJ])		option[numopt++]=O_XA;

	if(debug) for (opt=0; opt<numopt; opt++)
		dprint3("%c", "PMNX123"[option[opt]]);

	opt = option[rnd(numopt)];
	dprint3(" -> %c ","PMNX123"[opt]);

	switch(opt)
	{
		case O_PMS:
			dprint3("M");
		case O_PS:
			dprint3("PS ");
			strcpy(buf,names_select(PRE));
			if (opt==O_PMS) strcat(buf,names_select(MID));
			strcat(buf,names_select(SUF));
			cap(buf);
			break;

		case O_N:
			dprint3("N ");
			strcpy(buf1,names_select(NOUN));
			strcpy(buf2,names_select(NOUN));
			type1(buf,buf1,buf2);
			break;

		case O_X:
			dprint3("X ");
			strcpy(buf1,names_select(NADJ));
			strcpy(buf2,names_select(NADJ));
			type1(buf,buf1,buf2);
			break;

		case O_NA:
			dprint3("NA ");
			strcpy(buf1,names_select(NOUN));
			strcpy(buf2,names_select(ADJ));
			type2(buf,buf1,buf2);
			break;

		case O_XA:
			dprint3("XA ");
			strcpy(buf1,names_select(NOUN));
			if (rnd(2))
				strcpy(buf2,names_select(ADJ));
			else	strcpy(buf2,names_select(NADJ));
			type2(buf,buf1,buf2);
			break;

		case O_NX:
			dprint3("NX ");
			if (rnd(2))
				strcpy(buf1,names_select(NOUN));
			else	strcpy(buf1,names_select(NADJ));
			strcpy(buf2,names_select(ADJ));
			type2(buf,buf1,buf2);
			break;

		default:
			dprint3("? ");
			strcpy(buf,"[err]");
			break;
	}
	if (caps==2)
	{
		cap2(buf);
	}
}

void gen()
{
	int lin,col;

	for (lin=0; lin<LINES; lin++)
		for (col=0; col<COLUMNS; col++)
		{
			dprint1("gen: [%2d][%d]\n",lin,col);
			newname(scr[lin][col]);
			dprint1(" = \"%s\"\n",scr[lin][col]);
			saved[lin][col]=0;
		}
}

void display()
{
	int lin;
	static char tmp[200],*p;

	clear();
	for (lin=0; lin<LINES; lin++)
	{
		if (ansi)
		{
			/* this should be a tad faster on slow terminals */
			move(lin+1,1);
			printf("(%c) %s",
				(saved[lin][0]?SAVED:lin+'a'), scr[lin][0]);

			move(lin+1,41);
			printf("(%c) %s",
				(saved[lin][1]?SAVED:lin+'A'), scr[lin][1]);
		}
		else
		{
			printf("(%c) %-35s (%c) %-35s\n",
				(saved[lin][0]?SAVED:lin+'a'), scr[lin][0],
				(saved[lin][1]?SAVED:lin+'A'), scr[lin][1]);
		}

		if (debug>3)
		{
			sprintf(tmp,"(%c) %-35s (%c) %-35s\n",
				(saved[lin][0]?SAVED:lin+'a'), scr[lin][0],
				(saved[lin][1]?SAVED:lin+'A'), scr[lin][1]);

			p=tmp;

			while (*p)
			{
				if (*p=='\n') putchar('\n');
				else if (*p<' ') switch(*p)
				{
					case '\a': printf("\\a"); break;
					case '\b': printf("\\b"); break;
					case '\f': printf("\\f"); break;
					case '\r': printf("\\r"); break;
					case '\t': printf("\\t"); break;
					case '\v': printf("\\v"); break;
					default:   printf("[%d]",*p); break;
				}
				else putchar(*p);
				p++;
			}
		} /* debug */
	}
	move(LINES+2,1); printf("(SPACE) more   (ENTER) quit   (?) help\n");
	ready();
}

void savename(int row, int col)
{
	if (saved[row][col]) return;
	if (row<0 || col<0 || row>=LINES || col>=COLUMNS)
	{
		putchar(7);	/* beep */
		return;
	}

	/* open output file if it isn't already open */
	if (!isopen)
	{
		outfp = fopen(outfile,"a"); /* append */
		if (outfp)
			isopen=1;
	}

	/* if its open, write the name */
	if (isopen)
	{
		fprintf(outfp,"%s\n",scr[row][col]);
		saved[row][col] = 1;	/* remember we saved this one */
		move(row+1,(col*40)+2);
		putchar(SAVED);
		ready();
	}
}

void names()
{
	int c;
	int done=FALSE;

	if (forever)
	{
		for(;;)
		{
			newname(scr[0][0]);
			puts(scr[0][0]);
		}
	}
	else
	{
		kb_init();
		kb_wait();

		gen();
		display();

		do
		{
			c = getkey();
			switch(c)
			{
				case ' ':
					gen();
					display();
						break;
				case '?':
					helpscr();
					display();
					break;
			case '!':
					system("/bin/csh");
					break;
				case '\r':
				case '\n':
					done=TRUE;
					break;

				default:
					if (c>='a' && c<=('a'+19))
					{
						savename(c-'a', 0);
					}
					else if (c>='A' && c<=('A'+19))
					{
						savename(c-'A', 1);
					}
					break;
			}
		}
		while (!done);

		move(LINES+3,1);
		if (isopen) fclose(outfp);
		kb_done();
	}
}

