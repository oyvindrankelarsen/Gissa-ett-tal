#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "safeinput.h"

void menu()
{
    puts("**********************");
    puts("*** GISSA ETT TAL ****");
    puts("*** 1. Spela igen ****");
    puts("*** 2. Avsluta    ****");
    puts("*** 3. Se lowscore ***");
    puts("**********************\n");
    int val = 0;
    GetInputInt("Välj ur menyn: ", &val);

    if (val == 1)
        main();
    if (val == 2)
    {
        puts("\nTack för den här gången!");
        exit(0);
    }
    if (val == 3)
        readLowscore();

    else
        menu();
}

int slumpa()
{
    int lower = 1, upper = 100, count = 1, num = 0;
    srand(time(0));

    for (int i = 0; i < count; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
    }

    return num;
}
void readLowscore()
{
    FILE *fpr = fopen("lowscore.txt", "r");
    int count = 0;
    char row[100];
    char rows[5][100];
    while (fgets(row, sizeof row, fpr) != NULL)
    {
        if (strlen(row) > 3)
            strcpy(rows[count], row);

        count++;
    }
}

int readHighestLowscore()
{
    FILE *fpr = fopen("lowscore.txt", "r");
    int count = 0;
    char row[100];
    char rows[5][100];
    while (fgets(row, sizeof row, fpr) != NULL)
    {
        if (strlen(row) > 3)
            strcpy(rows[count], row);
        count++;
    }
    rows[4][0]
}

void writeLowscore()
{
    FILE *fpw = fopen("lowscore.txt", "w");
}

int gissaEttTal()
{
    int gissatTal = 0;
    while (!(GetInputInt("Gissa ett tal mellan 1 och 100. \n", &gissatTal)))
    {
    }

    if (gissatTal > 0 && gissatTal < 101)
        return gissatTal;

    gissaEttTal();
}

int main(void)
{
    puts("**********************");
    puts("*** GISSA ETT TAL ****");
    puts("**********************");
    int slumptal = 0, gissatTal = 0, countGissningar = 0;
    slumptal = slumpa();
    bool gissaIgen = true;
    while (gissaIgen)
    {

        gissatTal = gissaEttTal();
        countGissningar++;
        printf("Gissning %d: %d\n", countGissningar, gissatTal);

        if (slumptal > gissatTal)
            puts("\nTalet är större\n");
        else if (slumptal < gissatTal)
            puts("\nTalet är mindre\n");
        else
        {
            printf("\nRätt! Du gissade rätt på %d försök.\n", countGissningar);

            if (countGissningar < readHighestLowscore())
                writeLowscore();
            gissaIgen = false;
        }
    }
    menu();
    return 0;
}