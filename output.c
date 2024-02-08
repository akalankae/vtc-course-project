/****************************************************************************************
 * File name: output.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 09 Feb 24
 * Last modified: 09 Feb 24 12.32 AM
 * Description: VTC Course project functions related to printing data
 ***************************************************************************************/
#include <stdio.h>

#include "database.h"

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
