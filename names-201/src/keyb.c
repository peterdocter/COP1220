/*---------------------------------------------------------------------
 * Borrowed from chin.c v1.1, written by Davor Slamnig, 6/94          *
 * Modified by Michael Harvey 8/94                                    *
 *                                                                    *
 *  Single character keyboard input on UNIX in three modes:           *
 *	                                                              *
 *  wait    - getchar() blocks until a character is read.             *
 *  nowait  - getchar() returns immediately, -1 is returned           *
 *                      if there are no characters in queue.          *
 *  timeout - getchar() blocks until a character is read,             *
 *                      or a specified time limit is exceeded.        *
 *                                                                    *
 *      vidsetup(1, 0);           /* wait    * /                      *
 *      vidsetup(0, 0);           /* nowait  * /                      *
 *      vidsetup(0, V_TIMEOUT);   /* timeout * /                      *
 *                                                                    *
 *      vidsave();                /* save terminal           * /      *
 *      vidreset();               /* restore normal settings * /      *
 *                                                                    *
 *      kb_init();                /* init kb mode            * /      *
 *      kb_done();                /* reset kb mode           * /      *
 *      kb_shell();               /* shell mode              * /      *
 *                                                                    *
 *      kb_wait();                /* wait mode               * /      *
 *      kb_nowait();              /* nowait mode             * /      *
 *      kb_timeout();             /* timeout mode            * /      *
 *                                                                    *
 *  See termio(7)                                                     *
 ---------------------------------------------------------------------*/

#include <stdio.h>
#include <termio.h>
#include "keyb.h"

#define V_TIMEOUT 	10	/* 1 second */

struct termio Savevid;

void vid_save(vmin, vtime)
{
	if(ioctl(0, TCGETA, &Savevid) == -1)
	{
		perror("vidsave failed");
		return;
	}
}

void vid_setup(vmin, vtime)
int vmin, vtime;
{
	static struct termio newvid; /* must be static or global */
	
	if(ioctl(0, TCGETA, &newvid) == -1)
	{
		perror("TCGETA failed");
		return;
	}

	newvid.c_lflag = (newvid.c_lflag & ~ICANON & ~ECHO);
	newvid.c_cc[VMIN] = vmin;
	newvid.c_cc[VTIME] = vtime;

	if(ioctl(0, TCSETA, &newvid) == -1)
	{
		perror("vidsetup failed");
		return;
	}	
}

void vid_reset()
{
	if(ioctl(0, TCSETA, &Savevid) == -1)
	{
		perror("vidreset failed");
		return;
	}	
}

void vid_wait()
{
	/* wait mode    - getchar() blocks until a character is read. */

	vid_setup(1, 0);
}

void vid_nowait()
{
	/* nowait mode  - getchar() returns immediately, -1 is returned. */
	/*                if there are no characters in queue.           */

	vid_setup(0, 0);
}

void vid_timeout()
{
	/* timeout mode - getchar() blocks until a character is read, */
	/*                or a specified time limit is exceeded.      */
	
	vid_setup(0, V_TIMEOUT);
}

void kb_init()     { vid_save(0,0); }
void kb_done()     { vid_reset(); }
void kb_shell()    { vid_reset(); }
void kb_wait()     { vid_wait(); }
void kb_nowait()   { vid_nowait(); }
void kb_timeout()  { vid_timeout(); }

