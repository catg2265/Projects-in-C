#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 0, b = 0, large, small, i, j, denominator;
    do
    {
        printf("Enter 2 integers to find the common denominator, program will end with negative integer\n");
        scanf(" %d %d", &a, &b);
        if (a < b && a != 0 && b != 0)
        {
            small = a;
            large = b;
            for (i = small; i >= 0; i--)
            {
                denominator = large % i;
                if (denominator > 0)
                {
                    continue;
                }
                else
                {
                    printf("The common denominator of %d and %d is %d\n", a, b, i);
                    break;
                }
            }
        }
        else if (a > b && a != 0 && b != 0)
        {
            small = b;
            large = a;
            for (j = small; j >= 0; j--)
            {
                denominator = large % j;
                if (denominator > 0)
                {
                    continue;
                }
                else
                {
                    printf("The common denominator of %d and %d is %d\n", a, b, j);
                    break;
                }
            }
        }
        else
        {
            printf("Invalid input\n");
        }
        continue;
    }
    while(a > 0 && b > 0);
    printf("Program has been terminated\n");
    return EXIT_SUCCESS;
}