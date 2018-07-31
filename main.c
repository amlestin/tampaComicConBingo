#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Prototype */
char bingoGenerator(int length, int width, char randChoices[25][30], char bingoBoard[][length][width]);
char randomizer(char choices[25][30]);
void bingoPrinter(int length, int width, int tableNum, char bingoBoard[tableNum][length][width]);

int
main()
{
   /* Declarations */
   unsigned int leng, wdth, numTables, i;

   char options[25][30] = {"Gender Bender", "Slave Leia", "Guy with Boombox", "Jon Snow", "Mother of Dragons",
                "Deadpool", "Kid that parent dragged in", "Parent that kid dragged in", "Cardboard Costume",
                "Pokemon Trainer", "Costume Coordinated Group", "Placeholder 12", "Placeholder 13",
                "Placeholder 14", "Placeholder 15", "Placeholder 16", "Placeholder 17", "Placeholder 18",
                "Placeholder 19", "Placeholder 20", "Placeholder 21", "Placeholder 22", "Placeholder 23",
                "Placeholder 24", "Placeholder 25"};

   char randOps[25][30];

    printf("Please enter the length and width of your table: ");
    scanf("%u", &leng);
    wdth = leng;
    printf("How many tables are we making: ");
    scanf("%u", &numTables);

    //printf("\n%s", options[3]);
    //getch();

    char bingoTables[numTables][leng][wdth];

    for(i = 0; i < numTables; i++){
        randOps[i][30] = randomizer(options);
        printf("\n%s", randOps[i]);
        getch();
    }

    for(i = 0; i < numTables; i++){
        bingoTables[i][leng][wdth] = bingoGenerator(leng, wdth, randOps, bingoTables);
        printf("\n%c", bingoTables[i][leng][wdth]);
        getch();
    }

    for(i = 0; i < numTables; i++){
        bingoPrinter(leng, wdth, numTables, bingoTables);
    }

    printf("Live Long and May the Force Be Ever in Your Favor!");

    return 0;
}

char randomizer(char choices[25][30]){
    //time_t seed;
    size_t arrSz = 25;
    char randChoices[25][50];
    unsigned int i;

    srand(time(0));

    for(i=0; i < arrSz; i++){
        strcpy(randChoices[i], choices[rand() % (arrSz +1)]);
        printf("\n%s", randChoices[i]);
        printf("\n%s", "randomTest");
        getch();
    }

    return randChoices[25][50];
}

char bingoGenerator(int length, int width, char randChoices[25][30], char bingoBoard[][length][width]){
    char bingoTable[length][width];
    unsigned int i, j;

    for(i=0; i < length; i++){
       if (i < 1){
         for(j=0; j < width; j++){
            bingoTable[i][j] = randChoices[j][30];
         }
       }
       else{
            for(j=0; j < width; j++){
            bingoTable[i][j] = randChoices[(j + width)*i][30];
         }
       }
    }
    return bingoTable[length][width];
}

void bingoPrinter(int length, int width, int tableNum, char bingoTables[tableNum][length][width]){
    unsigned i, j, k;

    for(k=0; k < tableNum; k++){
        for(i=0; i < length; i++){
            for(j=0; j < width; j++){
                if (j < 1){
                    printf("%c", bingoTables[k][i][j]);
                }
                else{
                    printf("\t%c", bingoTables[k][i][j]);
                }
            }
        }
    }
}
