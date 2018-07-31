#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Prototype */
int bingoGenerator(int length, int width, char randChoices[30][30], char bingoBoard[length][width][30]);
int randomizer(char choices[30][30], char randChoices[30][30]);
void bingoPrinter(int length, int width, char bingoBoard[length][width][30], FILE *fileplace);

int
main()
{
   /* Declarations */
   unsigned int leng, wdth;

   FILE *fileData;
   fileData = fopen("bingoCard.txt", "w");

   char options[30][30] = {"Gender Bender", "Slave Leia", "Guy with Boombox", "Jon Snow", "Mother of Dragons",
                "Deadpool", "Kid that parent dragged in", "Parent that kid dragged in", "Cardboard Costume",
                "Pokemon Trainer", "Costume Coordinated Group", "Placeholder 12", "Placeholder 13",
                "Placeholder 14", "Placeholder 15", "Placeholder 16", "Placeholder 17", "Placeholder 18",
                "Placeholder 19", "Placeholder 20", "Placeholder 21", "Placeholder 22", "Placeholder 23",
                "Placeholder 24", "Placeholder 25", "Placeholder 26", "Placeholder 27", "Placeholder 28",
                "Placeholder 29", "Placeholder 30"};

   char randOps[30][30];

    printf("Please enter the length and width of your table: ");
    scanf("%u", &leng);
    wdth = leng;
    //printf("How many tables are we making: ");
    //scanf("%u", &numTables);

    //printf("\n%s", options[3]);
    //getch();

    char bingoTables[leng][wdth][30];

    //for(i = 0; i < numTables; i++){
        //randOps[i][30] = randomizer(options);
    randomizer(options, randOps);
        //printf("\n%s", randOps[i]);
        //printf("\n%s", "randomFuncCheck");
        //getch();
    //}

    //for(i = 0; i < numTables; i++){
    bingoGenerator(leng, wdth, randOps, bingoTables);
    //printf("\n%s", bingoTables[1][1]);
    //printf("\n%s", "tableFuncCheck");
    //getch();
    //}

    //for(i = 0; i < numTables; i++){
    bingoPrinter(leng, wdth, bingoTables, fileData);
    //}

    printf("Live Long and May the Force Be Ever in Your Favor!");

    return 0;
}

int randomizer(char choices[30][30], char randChoices[30][30]){
    //time_t seed;
    size_t arrSz = 30;
    unsigned int i;

    srand(time(0));

    for(i=0; i < arrSz; i++){
        strcpy(randChoices[i], choices[rand() % (arrSz +1)]);
        //printf("\n%s", randChoices[i]);
        //printf("\n%s", "randomTest");
        //getch();
    }

    return 0;
}

int bingoGenerator(int length, int width, char randChoices[30][30], char bingoBoard[length][width][30]){
    unsigned int i, j;

    //for(k=0; k < tableNum; k++){
    for(i=0; i < length; i++){
        if (i < 1){
            for(j=0; j < width; j++){
                strcpy(bingoBoard[i][j], randChoices[j]);
            }
        }
        else{
            for(j=0; j < width; j++){
                strcpy(bingoBoard[i][j], randChoices[(j + width)*i]);
            }
        }
    }
    return 0;
}

void bingoPrinter(int length, int width, char bingoTables[length][width][30], FILE *fileplace){
    unsigned i, j;
    fprintf(fileplace, "|\tB\t|\tI\t|\tN\t|\tG\t|\tO\t|\n");
    fprintf(fileplace, "|+++++++++++++++|+++++++++++++++"
                       "|+++++++++++++++|+++++++++++++++|+++++++++++++++|\n");
    for(i=0; i < length; i++){
        for(j=0; j < width; j++){
            if (j < 1){
                //printf("%s", bingoTables[i][j]);
                fprintf(fileplace, "%s\t", bingoTables[i][j]);
            }
            else if(j == (width - 1)){
                //printf("\t%s\n", bingoTables[i][j]);
                fprintf(fileplace,"\t\t%s\t\n", bingoTables[i][j]);
            }
            else{
                //printf("\t%s", bingoTables[i][j]);
                fprintf(fileplace, "\t%s\t", bingoTables[i][j]);
            }
        }
    }
}
