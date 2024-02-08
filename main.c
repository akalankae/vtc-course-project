/****************************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: 08 Feb 24 07.00 PM
 * Description: VTC Course Project
 * A program that a record shop might use to keep track of its inventory of CDs.
 * v0.1 - read title, artist name, number of tracks, album/single, price for one CD from
 * user and print all of them back
 * v0.2 - modularize and abstract away with functions, conditional compilation to include
 * or exclude artist
 ***************************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "database.h"
#include "util.h"

#define ALBUM 'a'
#define SINGLE 's'

int main(int argc, char *argv[])
{
    char titles[MAX_CDS][TITLE_LEN];    // name of CD
    char artists[MAX_CDS][ARTIST_LEN];  // artists name
    bool cd_type[MAX_CDS];              // true = ALBUM, false = SINGLE
    int ntracks[MAX_CDS];               // number of tracks
    float prices[MAX_CDS];              // price in dollars
    int num_cd;                         // index of current CD

    puts("CD Database Program");
    printf("You can enter store %d CDs in the database\n", MAX_CDS);

    for (num_cd = 0; num_cd < MAX_CDS; ++num_cd) {
        char reply;

        printf("Entering Data for CD #%02d\n", num_cd + 1);
        puts("=========================\n");

        // CD title
        read_string("Enter name of the CD: ", titles[num_cd], sizeof titles[num_cd]);

#ifndef NOARTIST
        // Artist name
        read_string("Enter name of the artist: ", artists[num_cd], sizeof titles[num_cd]);

#endif /* ifdef NOARTIST */

        // Number of tracks
        ntracks[num_cd] = read_int("Enter number of tracks: ");

        // ALBUM or SINGLE?
        cd_type[num_cd] = yesno("Is it an Album? (y/n) ");

        // price
        prices[num_cd] = read_float("Enter price of the CD: $");

        // Prompt for next CD
        if (!yesno("\nDo you wish to enter details for another CD? (y/n) ")) break;
        puts("");
    }

    printf("\nYou entered %u CDs\n", num_cd + 1);

    // Print CD info for all the CDs
    for (int j = 0; j <= num_cd; ++j) {
        output(
            titles[j],
#ifndef NOARTIST
            artists[j],
#endif /* ifdef NOARTIST */
            cd_type[j], ntracks[j], prices[j]);

        if (j < num_cd) enter("Press <Enter> to continue to next CD ");
    }

    return (EXIT_SUCCESS);
}
