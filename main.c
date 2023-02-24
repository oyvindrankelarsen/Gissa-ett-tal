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
    else if (val == 2)
    {
        puts("\nTack för den här gången!");
        exit(0);
    }
    else if (val == 3)
        puts("3.");

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
/*
void readLowscore() //--------------------------------------------------------------------------------------
{

    FILE *fpr = fopen("lowscore.txt", "r");

}

int readHighestLowscore() //-------------------------
{
    //ta högsta, dvs array[sizeof array -1].guesses
    FILE *fpr = fopen("lowscore.txt", "r");
}

void writeLowscore() //--------------------------------------------------------------------------------------
{
    // Datum och tid, namn och antal gissningar ska lagras
    FILE *fpw = fopen("lowscore.txt", "w");
    struct lowscore [5];
    time_t result = time(NULL);
    if (result != (time_t)(-1))
        printf("The current time is %s\n", asctime(localtime(&result)));
}
*/
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

    struct lowscore
    {
        char datetime[30];
        char name[30];
        int guesses[20];
    };

    struct lowscore lowestscores[5];

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
            // läs in structs i array

            // if (countGissningar < array[sizeof array -1].guesses)
            //   writeLowscore();
            gissaIgen = false;
        }
    }
    menu();
    return 0;
}