#include <stddef.h>

/* Array size constants */
#define MAX_CDS 100    // maximum number of CDs database can store
#define TITLE_LEN 32   // maximum length of CD title
#define ARTIST_LEN 64  // maximum length of artist name

/* Symbolic constants */
#define ALBUM 'a'
#define SINGLE 's'

/* function prototypes */
extern int yesno(const char prompt[]);
extern void enter(const char prompt[]);

#ifndef NOARTIST
extern void output(char title[], char artist[], bool is_album, int ntracks, float price);
#else
extern void output(char title[], bool is_album, int ntracks, float price);
#endif  // !NOARTIST
