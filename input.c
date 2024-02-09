/****************************************************************************************
 * File name: input.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 08 Feb 24
 * Last modified: 09 Feb 24 11.58 AM
 * Description: VTC course project functions.
 ***************************************************************************************/

#include <ctype.h>
#include <stdio.h>

#include "database.h"

/*
 * yesno()
 * Display given string parameter, then read a single character from the keyboard.
 * y/Y => return 1, n/N => return 0
 * Keep prompting until valid input is given (i.e. y, n, Y, N).
 */
extern int yesno(const char prompt[])
{
    char ans[16];

    for (;;) {
        fputs(prompt, stdout);
        fgets(ans, 16, stdin);
        switch (toupper(ans[0])) {
            case 'Y':
                return 1;
            case 'N':
                return 0;
            default:
                fputs("Please enter 'y' or 'n'\n", stderr);
                break;
        }
    }
}

/*
 * enter()
 * Display given string parameter and wait for user to press ENTER on the keyboard.
 */
extern void enter(const char prompt[])
{
    char ch;

    fflush(stdin);
    fputs(prompt, stdout);
    do {
        ch = getchar();
    } while (ch != '\n');
}

/*
 * read_cd(cd_t *)
 * Read in details of a single CD from keyboard and write it to CD using CD ptr parameter
 */
extern void read_cd(cd_t *cd_ptr)
{
    // CD title
    read_string("Enter name of the CD: ", cd_ptr->title, sizeof cd_ptr->title);

#ifndef NOARTIST
    // Artist name
    read_string("Enter name of the artist: ", cd_ptr->artist, sizeof cd_ptr->artist);

#endif /* ifdef NOARTIST */

    // Number of tracks
    cd_ptr->num_tracks = read_int("Enter number of tracks: ");

    // ALBUM or SINGLE?
    cd_ptr->album = yesno("Is it an Album? (y/n) ");

    // price
    cd_ptr->price = read_float("Enter price of the CD: $");
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

// read_string() display given string parameter and read string into given string
// parameter
extern void read_string(const char prompt[], char string[], size_t length)
{
    fputs(prompt, stdout);
    fgets(string, length, stdin);
    trim_nl(string, length);
}
