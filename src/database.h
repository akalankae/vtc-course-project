#include <stdbool.h>
#include <stddef.h>

/* Data types */
struct cd_type {
    char *title;  // name of CD
#ifndef NOARTIST
    char *artist;    // artists name
#endif               /* ifdef NOARTIST */
    int num_tracks;  // number of tracks
    bool album;      // true = ALBUM, false = SINGLE
    float price;     // price in dollars
};

typedef struct cd_type cd_t;

/* Function Prototypes */
extern int yesno(const char prompt[]);  // input.c
extern void enter(const char prompt[]);
extern int read_int(const char prompt[]);
extern float read_float(const char prompt[]);
extern void read_string(const char prompt[], char string[], size_t length);
extern void read_cd(cd_t *cd_ptr);
extern int get_opt(void);
extern void print_cd(const cd_t *cd_ptr);   // output.c
extern void trim_nl(char s[], size_t len);  // util.c
extern void clear_cd(cd_t *cd_ptr);

void create_list(void);
void open_list(void);
void save_list(void);
void save_list_as(void);
void append_list(void);
void create_record(void);
void display_record(void);
void display_all_records(void);
void quit(void);
