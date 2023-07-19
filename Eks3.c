/* Christoffer A. T. Graversen 
    A325a SW1*/
/* Dette program er blevet påvirket af Markus Thøgersen, 
https://stackoverflow.com/questions/8721189/how-to-sort-an-array-of-structs-in-c og
https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_MATCHES 182
#define SIZE_OF_TEAMS 14

struct team
{
    char *name;
    int point;
    int goalScored;
    int goalAgainst;
};
typedef struct team team;

struct match
{
    char spectator[6];
    char day[4];
    char time[6];
    char date[6];
    char teamOne[4];
    char teamTwo[4];
    char goalsIn[2];
    char goalsOut[2];
};
typedef struct match match;

void TeamInitialize(team *);
int CompareFunction(const void *, const void *);

int main()
{
    match matches[SIZE_OF_MATCHES];
    team teams[SIZE_OF_TEAMS];

    TeamInitialize(teams);

    FILE *fp;
    fp = fopen("kampe-2019-2020.txt", "r");
    for (int i = 0; i < SIZE_OF_MATCHES; i++)
    {
        fscanf(fp, " %[^ ] %[^ ] %[^ ] %[^ ] %*[-] %[^ ] %[^ ] %*[-] %[^ ] %[^ ]", (matches + i)->day, (matches + i)->date, (matches + i)->time, (matches + i)->teamOne, (matches + i)->teamTwo, (matches + i)->goalsIn, (matches + i)->goalsOut, (matches + i)->spectator);
        for (int j = 0; j < SIZE_OF_TEAMS; j++)
        {
            if (strcmp((matches + i)->teamOne, (teams + j)->name) == 0)
            {
                (teams + j)->goalScored += atoi((matches + i)->goalsIn);
                (teams + j)->goalAgainst += atoi((matches + i)->goalsOut);
                if (atoi((matches + i)->goalsIn) == atoi((matches + i)->goalsOut))
                {
                    (teams + j)->point += 1;
                }
                else if (atoi((matches + i)->goalsIn) > atoi((matches + i)->goalsOut))
                {
                    (teams + j)->point += 3;
                }
            }
            else if (strcmp((matches + i)->teamTwo, (teams + j)->name) == 0)
            {
                (teams + j)->goalScored += atoi((matches + i)->goalsOut);
                (teams + j)->goalAgainst += atoi((matches + i)->goalsIn);
                if (atoi((matches + i)->goalsIn) == atoi((matches + i)->goalsOut))
                {
                    (teams + j)->point += 1;
                }
                else if (atoi((matches + i)->goalsIn) < atoi((matches + i)->goalsOut))
                {
                    (teams + j)->point += 3;
                }
            }
        }
    }
    qsort(teams, SIZE_OF_TEAMS, sizeof(team), CompareFunction);
    for (int i = 0; i < SIZE_OF_TEAMS; i++)
    {
        printf(" %3s  Points: %d  Goals scored: %d  Goals scored against: %d \n", (teams+i)->name, (teams+i)->point, (teams+i)->goalScored, (teams+i)->goalAgainst);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void TeamInitialize(team *teams)
{
    char *names[SIZE_OF_TEAMS] = {"FCK", "AaB", "AGF", "FCN", "FCM", "EFB", "SDR", "RFC", "OB", "BIF", "SIF", "HOB", "ACH", "LBK"};
    for (int i = 0; i < SIZE_OF_TEAMS; i++)
    {
        teams[i].name = names[i];
        teams[i].point = 0;
        teams[i].goalScored = 0;
        teams[i].goalAgainst = 0;
    }
}

int CompareFunction(const void *a, const void *b)
{
    const team *t1 = (team *)a;
    const team *t2 = (team *)b;
    if (t1->point > t2->point)
        return -1;
    else if (t1->point < t2->point)
        return +1;
    else if (t1->goalScored > t2->goalScored)
        return -1;
    else if (t1->goalScored < t2->goalScored)
        return +1;
    else
        return 0;
}