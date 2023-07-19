#include <stdio.h>

int main(void){
    //2 feet = 0.61 m
    double y1 = 0.0, y2 = 0.0, h1 = 0.0, h2 = 0.0;
    double spd = 0.61;
    double tot_Area = 0.0;
    double tot_Spd = 0.0;
    printf("Enter sides of yard: ");
    scanf(" %lf %lf", &y1, &y2);
    printf("Enter sides of house: ");
    scanf(" %lf %lf", &h1, &h2);
    tot_Area = (y1*y2)-(h1*h2);
    tot_Spd = tot_Area / spd;
    printf("Lawn will be mowed in =%lf"" seconds", tot_Spd);
}