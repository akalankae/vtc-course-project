/****************************************************************************************
 * File name: util.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 07 Feb 24
 * Last modified: 08 Feb 24 06.02 PM
 * Description: utility functions for main program
 * get_string() => read in a string from stdin with its NEWLINE char removed
 ***************************************************************************************/
#include "util.h"

#include <stdio.h>

extern char *get_string(char *buffer, size_t nchars)
{
    fgets(buffer, nchars, stdin);
    for (int i = 0; i < nchars; ++i)
        if (buffer[i] == '\n') buffer[i] = '\0';

    return buffer;
}

// read_int() display given string parameter and read and return an integer
extern int read_int(const char prompt[])
{
    int n;
    fputs(prompt, stdout);
    scanf("%d%*c", &n);
    return n;
}

// read_float() display given string parameter and read and return a float
extern float read_float(const char prompt[])
{
    float f;
    fputs(prompt, stdout);
    scanf("%f%*c", &f);
    return f;
}

// read_string() display given struct parameter and read string into given string
// parameter
extern void read_string(const char prompt[], char string[], size_t length)
{
    fputs(prompt, stdout);
    fgets(string, length, stdin);
    trim_nl(string, length);
}

// trim_nl() trim newline charater from the end of a string
static void trim_nl(char s[], size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        switch (s[i]) {
            case '\0':
                return;
            case '\n':
                s[i] = '\0';
        }
    }
}
