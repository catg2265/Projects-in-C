#include <stdio.h>
#include <stdlib.h>

int main(void){
    int watt;
    printf("Insert watt: ");
    scanf(" %d", &watt);
    switch (watt)
    {
    case 15:
        printf("Result: 125 Lumens");
        break;
    case 25:
        printf("Result: 215 Lumens");
        break;
    case 40:
        printf("Result: 500 Lumens");
        break;
    case 60:
        printf("Result: 880 Lumens");
        break;
    case 75:
        printf("Result: 1000 Lumens");
        break;
    case 100:
        printf("Result: 1675 Lumens");
        break;
    default:
        printf("Can't calculate");
        break;
    }
    return EXIT_SUCCESS;
}