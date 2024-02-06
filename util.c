/****************************************************************************************
 * File name: util.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 07 Feb 24
 * Last modified: 07 Feb 24 02.10 AM
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
