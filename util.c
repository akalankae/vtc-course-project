/****************************************************************************************
 * File name: util.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 07 Feb 24
 * Last modified: 09 Feb 24 06.22 PM
 * Description: utility functions for main program
 * get_string() => read in a string from stdin with its NEWLINE char removed
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"

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

/*
 * clear_cd(cd_t *)
 * Deallocate dynamic memory reserved for string fields of a CD structure
 * NB: these are dynamically allocated strings pointed to by (char *) title, artist
 */
void clear_cd(cd_t *cd_ptr)
{
    free(cd_ptr->title);
    free(cd_ptr->artist);
}
