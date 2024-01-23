/****************************************************************************************
 * File name: main.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 21 January 2024
 * Last modified: <date time>
 * Description: A program that a record shop might use to keep track of its inventory of CDs.
 ***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE 32
#define MAX_ARTIST_NAME 64

int main(int argc, char *argv[])
{
    char title[MAX_TITLE + 1];    // name of CD
    char artist[MAX_ARTIST_NAME]; // name of the artist
    int ntracks;                  // number of tracs
    char album;                   // is it an ALBUM? or is it a SINGLE?
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
        printf("Is it an album (y/n)? ");
        scanf("%c%*c", &album);
    } while (album != 'y' && album != 'Y' && album != 'n' && album != 'N');

    // price
    printf("Enter price of the CD: $");
    scanf("%lf", &price);

    printf("\n**************************************************\n");
    printf("     Title: %s\n", title);
    printf("     Artist: %s\n", artist);
    printf("     Number of tracks: %d\n", ntracks);
    printf("     Type: %s\n", album == 'y' || album == 'Y' ? "Album" : "Single");
    printf("     Retail price: %lf\n", price);
    printf("**************************************************\n");

    return (EXIT_SUCCESS);
}
