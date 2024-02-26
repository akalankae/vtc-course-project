/****************************************************************************************
 * File name: input.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 08 Feb 24
 * Last modified: 17 Feb 24 02.12 AM
 * Description: VTC course project functions.
 ***************************************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"

#define BUF_SIZ 32  // max possible length of CD title and artist name

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
    char read_buf[BUF_SIZ];  // tmp buffer to read artist name and CD title into

    // CD title
    // read_string("Enter name of the CD: ", cd_ptr->title, sizeof cd_ptr->title);
    read_string("Enter name of the CD: ", read_buf, BUF_SIZ);
    cd_ptr->title = strdup(read_buf);

    if (cd_ptr->title == NULL) {
        perror("strdup");
        exit(1);
    }

#ifndef NOARTIST
    // Artist name
    read_string("Enter name of the artist: ", read_buf, BUF_SIZ);
    cd_ptr->artist = strdup(read_buf);

    if (cd_ptr->artist == NULL) {
        perror("strdup");
        exit(1);
    }

#endif /* ifdef NOARTIST */

    // Number of tracks
    cd_ptr->num_tracks = read_int("Enter number of tracks: ");

    // ALBUM or SINGLE?
    cd_ptr->album = yesno("Is it an Album? (y/n) ");

    // price
    cd_ptr->price = read_float("Enter price of the CD: $");
}

/*
 * read_int()
 * Display given string parameter and get an integer from stdin
 */
extern int read_int(const char prompt[])
{
    int n;
    fputs(prompt, stdout);
    scanf("%d%*c", &n);
    return n;
}

/*
 * read_float()
 * Display given string parameter and get a float from stdin
 */
extern float read_float(const char prompt[])
{
    float f;
    fputs(prompt, stdout);
    scanf("%f%*c", &f);
    return f;
}

/*
 * read_string()
 * Display given string parameter and read string of chars (including NEWLINE) into given
 * char array
 * NOTE: assumes given char array has enough space to hold all of the user entered chars
 */
extern void read_string(const char prompt[], char string[], size_t length)
{
    fputs(prompt, stdout);
    fgets(string, length, stdin);
    trim_nl(string, length);
}

/*
 * get_option()
 * Display a list of user options and return one integer option.
 */
extern int get_opt(void)
{
    int opt;
    bool valid_opt;
    char menu[] =
        "\nPlease choose ONE of the following options:\n"
        "\n    File\n"
        "    ====\n"
        "  1. Create a new list\n"
        "  2. Open an existing list\n"
        "  3. Save the list\n"
        "  4. Save the list with a new name\n"
        "  5. Append the list to another file\n"
        "\n    Edit\n"
        "    ====\n"
        "  6. Create a new record\n"
        "\n    View\n"
        "    ====\n"
        "  7. Display a specific record\n"
        "  8. Display all the records\n"
        "\n  9. Exit\n"
        "\nPlease enter your choice? ";

    do {
        opt = read_int(menu);
        if (!(valid_opt = opt > 0 && opt < 10))
            fprintf(stderr, "%d is not a valid option!\n", opt);

    } while (!valid_opt);

    return opt;
}
