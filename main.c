/****************************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: 09 Feb 24 06.10 PM
 * Description: VTC Course Project
 * A program that a record shop might use to keep track of its inventory of CDs.
 * v0.1 - read title, artist name, number of tracks, album/single, price for one CD from
 * user and print all of them back
 * v0.1.1 - modularize and abstract away with functions, conditional compilation to
 * include or exclude artist
 * v0.2 - use structures to encapsulate a CD
 * v0.3 - Modify the project to ask "How many CDs do you have to enter?" at the beginning
 * of the program.  Allocate memory for that many CDs (instead 100) and prompt for details
 * accordingly.  Modify so that each CD uses only the memory absolultely needed to store
 * the string fields (i.e. CD title, Artist name) - HINT: use "strdup()" for latter.
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "database.h"

int main(int argc, char *argv[])
{
    unsigned total_cds;
    cd_t *cds;  // pointer to array of CDs in dynamic memory
    int i;      // index of current CD

    puts("\tCD Database Program\n\t===================");
    total_cds = read_int("How many CDs do you want to enter? ");

    // allocate memory for all CDs, if fails exit program
    cds = malloc(total_cds * sizeof(cd_t));
    if (cds == NULL) {
        fprintf(stderr, "Not enough memory or malloc subsystem failed!\n");
        return (EXIT_FAILURE);
    }

    // read in data for each CD
    for (i = 0; i < total_cds; ++i) {
        // Prompt for next CD
        if (!yesno("\nDo you wish to enter details for the next CD? (y/n) ")) break;

        puts("");
        printf("\nEntering Data for CD #%02d\n", i + 1);
        puts("=========================\n");

        read_cd(&cds[i]);
    }

    printf("\nYou entered %u CDs\n", i);

    // Print CD info for all the CDs & deallocate dynamic memory used by each CD
    for (int j = 0; j < i; ++j) {
        print_cd(&cds[j]);
        clear_cd(&cds[j]);

        if (j < i - 1) enter("Press <Enter> to continue to next CD ");
    }

    free(cds);
    return (EXIT_SUCCESS);
}
