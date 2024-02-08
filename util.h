#include <stdio.h>

#ifndef UTIL_H
#define UTIL_H

// get string from terminal with NEWLINE removed
extern char *get_string(char *buffer, size_t nchars);
extern int read_int(const char prompt[]);
extern float read_float(const char prompt[]);
extern void read_string(const char prompt[], char string[], size_t string_len);
static void trim_nl(char s[], size_t len);

#endif  // !UTIL_H
