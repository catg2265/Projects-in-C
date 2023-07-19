#include <stdio.h>
#include <stdlib.h>

int main(void){
    int watt;
    printf("Insert watt: ");
    scanf(" %d", &watt);
    if (watt == 15)
    printf("Result: 125 Lumens");
    else if (watt == 25)
    printf("Result: 215 Lumens");
    else if (watt == 40)
    printf("Result: 500 Lumens");
    else if (watt == 60)
    printf("Result: 880 Lumens");
    else if (watt == 75)
    printf("Result: 1000 Lumens");
    else if (watt == 100)
    printf("Result: 1675 Lumens");
    else
    printf("Illegal input");
    return EXIT_SUCCESS;
}