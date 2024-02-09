/****************************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: 09 Feb 24 12.03 PM
 * Description: VTC Course Project
 * A program that a record shop might use to keep track of its inventory of CDs.
 * v0.1 - read title, artist name, number of tracks, album/single, price for one CD from
 * user and print all of them back
 * v0.1.1 - modularize and abstract away with functions, conditional compilation to
 * include or exclude artist
 * v0.2 - use structures to encapsulate a CD
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "database.h"

#define MAX_CDS 100  // maximum number of CDs database can store

int main(int argc, char *argv[])
{
    cd_t cds[MAX_CDS];
    int i;  // index of current CD

    puts("CD Database Program");
    printf("You can enter store %d CDs in the database\n\n", MAX_CDS);

    for (i = 0; i < MAX_CDS; ++i) {
        printf("Entering Data for CD #%02d\n", i + 1);
        puts("=========================\n");

        read_cd(&cds[i]);

        // Prompt for next CD
        if (!yesno("\nDo you wish to enter details for another CD? (y/n) ")) break;
        puts("");
    }

    printf("\nYou entered %u CDs\n", i + 1);

    // Print CD info for all the CDs
    for (int j = 0; j <= i; ++j) {
        print_cd(cds[j]);

        if (j < i) enter("Press <Enter> to continue to next CD ");
    }

    return (EXIT_SUCCESS);
}
