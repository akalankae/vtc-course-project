#include <stdbool.h>
#include <stddef.h>

/* Array size constants */
#define MAX_CDS 100    // maximum number of CDs database can store
#define TITLE_LEN 32   // maximum length of CD title
#define ARTIST_LEN 64  // maximum length of artist name

/* Data types */
struct cd_type {
    char title[TITLE_LEN];  // name of CD
#ifndef NOARTIST
    char artist[ARTIST_LEN];  // artists name
#endif                        /* ifdef NOARTIST */
    int num_tracks;           // number of tracks
    bool album;               // true = ALBUM, false = SINGLE
    float price;              // price in dollars
};

typedef struct cd_type cd_t;

/* Function Prototypes */
extern int yesno(const char prompt[]);
extern void enter(const char prompt[]);
extern int read_int(const char prompt[]);
extern float read_float(const char prompt[]);
extern void read_string(const char prompt[], char string[], size_t length);
extern cd_t read_cd(void);
extern void print_cd(const cd_t cd);
extern void trim_nl(char s[], size_t len);  // utility functions
