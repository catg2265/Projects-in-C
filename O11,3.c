#include <stdio.h>
#include <stdlib.h>

int quotient(int dividend, int divisor);

int modulus(int dividend, int divisor);

int main (){

    int d1 = 58, d2 = 5;

    printf("Quotient of %i and %i is %i\n", d1, d2, quotient(d1, d2));

    return 0;
}

int quotient(int dividend, int divisor){
    int result = 1;
    if (dividend - divisor >= 0)
    {   
        result += quotient(dividend-divisor, divisor);
    } else
    {
        return 0;
    }
    
    return result;
}


int modulus(int dividend, int divisor){
    return dividend % divisor;
}
