/* Names v2.01 Copyright 1995 by Michael Harvey */

#include <string.h>
#include <ctype.h>
#include "names.h"

#define BUF 256
char buf[BUF];

#ifdef TURBOC
#define strncasecmp(d,s,n) strnicmp(d,s,n)
#endif

char * label[6] =
{
	"PRE","MID","SUF","NOUN","NADJ","ADJ"
};

char * strlwr(char *buf)
/* "string-lower": convert string to lower case */
{
	char *p;

	for (p=buf; *p; p++)
		if (*p>='A' && *p<='Z')
			*p += ('a'-'A');

	return buf;
}

int findmode(char * buf)
{
	int i;
	for (i=0; i<NONE; i++)
	{
		if (strncasecmp(buf,label[i],strlen(label[i])) == 0)
			return i;
	}
	dprint1("* findmode: unknown directive \"#%s\"\n",buf);
	return NONE;
}

void addelem(int mode, char * buf)
{
	char *p;

	if (mode<0 || mode>=NONE)
	{
		dprint("* addelem: bad mode (%d)\n",mode);
		return;
	}

	if (siz[mode] < DATASIZ)
	{
		dprint3("  addelem(%s)\n",buf);
		p = strdup(buf);
		if (p==NULL)
		{
			dprint("* addelem: strdup() failed\n");
		}
		else
		{
			data[mode][siz[mode]] = p;
			siz[mode]++;
		}
	}
	else dprint("* addelem: array full\n");
}

void readdata(FILE *inFile)
{
	char *p;

	int mode = NONE;

	if (inFile)
	{
		while (fgets(buf, BUF, inFile) != NULL)
		{
			dprint3("  readdata: \"%s\"",buf);

			if (cvt) strlwr(buf);

			/* find end of string */
			for(p=buf; *p; p++) ;

			/* p now points to '\0' */
			/* find last character */
			--p;
			while (p>buf && isspace(*p))
				--p;
			/* now we're on the last character */
			if (!isspace(*p)) p++;
			*p='\0';

			*p=0;

			if (*buf == '#')
				mode = findmode(buf+1);
			else
				addelem(mode,buf);
		}
	}
	else { dprint("Null FILE pointer in readdata()"); }
}

