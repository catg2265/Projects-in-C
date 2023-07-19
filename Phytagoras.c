#include <stdio.h>

int main(void){
    int m = 0, n = 0;
    printf("Please enter 2 positive integers, the first being bigger than the second: ");
    scanf(" %d %d", &m, &n);
    int side1 = (m*m) - (n*n);
    int side2 = 2*m*n;
    int hyp = (m*m) + (n*n);
    printf("Side 1 = %d\nSide 2 = %d\nHypotenusen = %d\n", side1, side2, hyp);
}