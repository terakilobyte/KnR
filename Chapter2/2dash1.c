#include <stdio.h>

/*
 * This program's purpose is to find the ranges of char, short, int, and long variables.
 * Signed and unsigned.
 * Solution to K&R exercise 2-1.
 */

#define BITS 8 // the number of bits in a byte
#define BASE2 2 // binary

void getSize(unsigned long bytes, char type[]);
unsigned long power(int base, int exponent);

int main(void)
{
    getSize(sizeof(char), "char");
    getSize(sizeof(short), "short");
    getSize(sizeof(int), "int");
    getSize(sizeof(long), "long");
                 
    return 0;
}

void getSize(unsigned long bytes, char type[])
{
    unsigned long upper;
    long lower;
    long signedUpper;
    int expo = bytes * BITS;

    upper = power(BASE2, expo);
    lower = ((upper / 2) + 1) * -1;
    signedUpper = upper / 2;

    printf("The ranges of type %s are:\tUnsigned: 0 to %lu\t\tSigned: %-li to %li\n", type, upper, lower, signedUpper);

}

unsigned long power(int base, int exponent)
{
    int i;
    unsigned long answer = base;

    for (i = 1; i < exponent - 1; i++)
    {   
        answer *= base;
    }
    // making sure we don't pop over into the next byte and go outside our container
    answer += (answer - 1);

    return answer;
}
