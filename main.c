/****************************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: 07 Feb 24 02.03 AM
 * Description: VTC Course Project
 * A program that a record shop might use to keep track of its inventory of CDs.
 * v0.1 - read title, artist name, number of tracks, album/single, price for one CD from
 * user and print all of them back
 ***************************************************************************************/
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#define MAX_CD 100
#define MAX_TITLE 32
#define MAX_ARTIST_NAME 64
#define ALBUM 'a'
#define SINGLE 's'

int main(int argc, char *argv[])
{
    char titles[MAX_CD][MAX_TITLE];         // name of CD
    char artists[MAX_CD][MAX_ARTIST_NAME];  // name of the artist
    bool are_albums[MAX_CD];                // is it an ALBUM? or is it a SINGLE?
    int ntracks[MAX_CD];                    // number of tracs
    double prices[MAX_CD];                  // price in dollars
    char cd_type;                           // 'a' for album, 's' for single
    int num_cd;                             // index of current CD

    puts("CD Database Program");
    printf("You can enter store %d CDs in the database\n", MAX_CD);

    for (num_cd = 0; num_cd < MAX_CD; ++num_cd) {
        char reply;

        printf("Entering Data for CD #%02d\n", num_cd + 1);
        puts("=========================\n");

        // CD title
        fputs("Enter name of the CD: ", stdout);
        get_string(titles[num_cd], MAX_TITLE);
        // Artist name
        fputs("Enter name of the artist: ", stdout);
        get_string(artists[num_cd], MAX_ARTIST_NAME);
        // Number of tracks
        fputs("Enter number of tracks: ", stdout);
        scanf("%d%*c", &ntracks[num_cd]);

        // ALBUM or SINGLE?
        do {
            fputs(
                "Is it an ALBUM or a SINGLE? ('a' for album or 's' for single)\n>> ",
                stdout);
            scanf("%c%*c", &cd_type);
            cd_type = tolower(cd_type);

            if (cd_type != ALBUM && cd_type != SINGLE)
                fputs("Error: Please enter \"a\" or \"s\" only!\n", stderr);

        } while (cd_type != ALBUM && cd_type != SINGLE);  // do-while

        are_albums[num_cd] = (cd_type == ALBUM);

        // price
        fputs("Enter price of the CD: $", stdout);
        scanf("%lf%*c", &prices[num_cd]);

        // Prompt for next CD
        fputs("\nDo you wish to enter details for another CD? (y/N) ", stdout);
        scanf("%c%*c", &reply);
        reply = tolower(reply);

        if (reply != 'y') break;
    }

    printf("\nYou entered %u CDs\n", num_cd + 1);

    // Print CD info for all the CDs
    for (int j = 0; j <= num_cd; ++j) {
        puts("\n**************************************************");
        printf("     Title: %s\n", titles[j]);
        printf("     Artist: %s\n", artists[j]);
        printf("     Number of tracks: %d\n", ntracks[j]);
        printf("     Type: %s\n", are_albums[j] ? "Album" : "Single");
        printf("     Retail price: %.2lf\n", prices[j]);
        puts("**************************************************\n");

        if (j < num_cd) {
            fflush(stdin);
            fputs("Press <Enter> to continue to next CD ", stdout);
        }
    }

    return (EXIT_SUCCESS);
}
