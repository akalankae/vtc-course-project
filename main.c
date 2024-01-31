/*******************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: 31 Jan 24 07.29 PM
 * Description: VTC Course Project
 * A program that a record shop might use to keep track of its inventory of CDs.
 * v0.1 - read title, artist name, number of tracks, album/single, price for one
 * CD from user and print all of them back
 ******************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE 32
#define MAX_ARTIST_NAME 64
#define ALBUM 'a'
#define SINGLE 's'

int main(int argc, char *argv[])
{
    char title[MAX_TITLE + 1];    // name of CD
    char artist[MAX_ARTIST_NAME]; // name of the artist
    int ntracks;                  // number of tracs
    bool is_album;                // is it an ALBUM? or is it a SINGLE?
    char cd_type;                 // 'a' for album, 's' for single
    double price;                 // price in dollars

    // CD title
    printf("Enter name of the CD: ");
    scanf("%[^\n]%*c", title);
    // Artist name
    printf("Enter name of the artist: ");
    scanf("%[^\n]%*c", artist);
    // Number of tracks
    printf("Enter number of tracks: ");
    scanf("%d%*c", &ntracks);

    // ALBUM or SINGLE?
    do
    {
        printf("What's the type of the CD? ('a' for album, 's' for single)\n> ");
        scanf("%c%*c", &cd_type);
        if (cd_type != ALBUM && cd_type != SINGLE)
        {
            fprintf(stderr, "Error: Please enter \"%c\" or \"%c\" only!\n", ALBUM, SINGLE);
        }

    } while (cd_type != ALBUM && cd_type != SINGLE); // do-while

    is_album = cd_type == ALBUM;

    // price
    printf("Enter price of the CD: $");
    scanf("%lf", &price);

    printf("\n**************************************************\n");
    printf("     Title: %s\n", title);
    printf("     Artist: %s\n", artist);
    printf("     Number of tracks: %d\n", ntracks);
    printf("     Type: %s\n", is_album ? "Album" : "Single");
    printf("     Retail price: %lf\n", price);
    printf("**************************************************\n");

    return (EXIT_SUCCESS);
}
