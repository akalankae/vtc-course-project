/****************************************************************************************
 * File name: database.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 08 Feb 24
 * Last modified: 08 Feb 24 07.01 PM
 * Description: VTC course project functions.
 ***************************************************************************************/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

// yesno() function displays its string parameter, then reads one character from the
// keyboard until that character is either Y or N.  Then the value 1 or 0 is returned,
// depending on the read character.
extern int yesno(char prompt[])
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
extern void enter(char prompt[])
{
    char ch;

    fflush(stdin);
    fputs(prompt, stdout);
    do {
        ch = getchar();
    } while (ch != '\n');
}

// output() function takes details of a single CD as arguments and prints them out to the
// screen.
extern void output(
    char title[],
#ifndef NOARTIST
    char artist[],
#endif /* ifdef NOARTIST */
    bool is_album, int ntracks, float price)
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
        title,
#ifndef NOARTIST
        artist,
#endif /* ifdef NOARTIST */
        ntracks, is_album ? "Album" : "Single", price);
}
