/****************************************************************************************
 * File name: database.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 08 Feb 24
 * Last modified: 09 Feb 24 12.04 AM
 * Description: VTC course project functions.
 ***************************************************************************************/

#include "database.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "util.h"

// yesno() function displays its string parameter, then reads one character from the
// keyboard until that character is either Y or N.  Then the value 1 or 0 is returned,
// depending on the read character.
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

// enter() function takes a single string parameter, which it displays and then waits for
// user to press ENTER on the keyboard.
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
 * print_cd()
 * Print details of a single CD to screen.
 */
extern void print_cd(const cd_t cd)
{
    printf(
        "\n**************************************************\n"
        "     Title: %s\n"
#ifndef NOARTIST
        "     Artist: %s\n"
#endif /* ifdef NOARTIST */

        "     Number of tracks: %d\n"
        "     %s\n"  // album/single
        "     Retail price: $%.2f\n"
        "**************************************************\n\n",
        cd.title,
#ifndef NOARTIST
        cd.artist,
#endif /* ifdef NOARTIST */
        cd.num_tracks, cd.album ? "Album" : "Single", cd.price);
}

/*
 * read_cd()
 * Read in details of a single CD from keyboard
 */
extern cd_t read_cd(void)
{
    cd_t cd;

    // CD title
    read_string("Enter name of the CD: ", cd.title, sizeof cd.title);

#ifndef NOARTIST
    // Artist name
    read_string("Enter name of the artist: ", cd.artist, sizeof cd.artist);

#endif /* ifdef NOARTIST */

    // Number of tracks
    cd.num_tracks = read_int("Enter number of tracks: ");

    // ALBUM or SINGLE?
    cd.album = yesno("Is it an Album? (y/n) ");

    // price
    cd.price = read_float("Enter price of the CD: $");

    return cd;
}
