/*
 * This program uses functions to convert from fahrenheit to celsius
 * and vice versa
 */

#include <stdio.h>

float ftoC(float fahr)
{
    return (5.0/9.0) * (fahr - 32);
}

float ctoF(float cels)
{
    return 1.8 * (cels + 32);
}

int main(int argc, char *argv[])
{
    int step = 20;

    int i;

    printf("Fahrenheit to Celsius Table:\n");
    for (i = -40; i < 300; i += step)
    {
        printf("%4.1f\t%4.1f\n", i, ftoC(i));
    }

    printf("Celsius to Fahrenheit Table:\n");
    for (i = -40; i < 200; i += step)
    {
        printf("%4.1f\t%4.1f\n", i, ctoF(i));
    }
    return 0;
}
        
