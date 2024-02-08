/****************************************************************************************
 * File name: util.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 07 Feb 24
 * Last modified: 09 Feb 24 12.49 AM
 * Description: utility functions for main program
 * get_string() => read in a string from stdin with its NEWLINE char removed
 ***************************************************************************************/
#include <stdio.h>

extern char *get_string(char *buffer, size_t nchars)
{
    fgets(buffer, nchars, stdin);
    for (int i = 0; i < nchars; ++i)
        if (buffer[i] == '\n') buffer[i] = '\0';

    return buffer;
}

// trim_nl() trim newline charater from the end of a string
extern void trim_nl(char s[], size_t len)
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
