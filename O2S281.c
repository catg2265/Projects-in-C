#include <stdio.h>
#include <stdlib.h>

int main()
{
    int years = 0, population = 9870.0;
    while (population < 30000){
        years++;
        population *= 1.1;
        printf("After %d years the population is: %d\n", years, population);
    }
    printf("It took %d years to exceed 30000", years);
    return EXIT_SUCCESS;
}