/****************************************************************************************
 * File name: output.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 09 Feb 24
 * Last modified: 09 Feb 24 12.01 PM
 * Description: VTC Course project functions related to printing data
 ***************************************************************************************/
#include <stdio.h>

#include "database.h"

/*
 * print_cd(cd_ptr *)
 * Print details of a single CD to screen.
 */
extern void print_cd(const cd_t *cd_ptr)
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
        cd_ptr->title,
#ifndef NOARTIST
        cd_ptr->artist,
#endif /* ifdef NOARTIST */
        cd_ptr->num_tracks, cd_ptr->album ? "Album" : "Single", cd_ptr->price);
}
