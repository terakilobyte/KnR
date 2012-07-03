#include <stdio.h>
#include <ctype.h>

/*
 * I learned a lot doing these exercises.  I'm probably just stupid and learn slowly,
 * but after spending a full day mulling over bitwise logic, it finally clicked and I
 * was able to complete all the solutions in an evening.
 *
 * I came up with the solutions for exercises on my own.  I used a pen and paper and the programmer mode of the calculator on my mac.
 * I did come across the solutions for circular rotation (exercise 2-8) on Wikipedia after finishing, and that's what inspired the
 * one liner return in the bonus solution.
 */

#define SHIFT (p + 1 - n)

unsigned int getbits(int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/*
 * Exercise 2-6.  Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */
unsigned int setbits(int x, int p, int n, int y)
{   
    // create a mask for the right n bits of y
    int mask = ((1 << n) - 1);

    // apply and position the mask
    y = (y & mask) << SHIFT;

    // shift y into the correct position
    //y <<= SHIFT;

    // now get the area from x we want to edit and make a mask with it
    mask = getbits(x, p, n);

    // shift our mask into position and xor out the bits
    x ^= (mask << SHIFT);

    // copy the value from y into x and return it
    return x | y;
}

/*
 * Exercise 2-7.  Write a function invet(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.i., 1 changed into 0 and vice versa), leaving
 * the others unchanged.
 */
unsigned int invert(unsigned int x, int p, int n)
{   
    // create a mask of the bits we want to reverse
    unsigned int mask = getbits(x, p, n);

    // create an inverse of the mask
    unsigned int inverse = ~mask ;

    // create a mask for the inverse
    unsigned int inverseMask = ((1 << n) - 1);

    // mask the inverse and shift it into position
    inverse = (inverse & inverseMask);
    inverse <<= SHIFT;

    // shift the mask into position and xor out the bits
    x ^= (mask << SHIFT);

    // copy the value over and return it
    return x | inverse;
    
}

/*
 * Exercise 2-8.  Write a function rightrot(x, n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */
unsigned int rightrot(unsigned int x, int n)
{
    // create a variable to hold the bits that are going to be pushed off
    unsigned int temp;

    // -1 to negate the +1 added by getbits
    temp = getbits(x, n-1, n);

    // shift x to the right n bit positions
    x >>= n;

    // shift temp to the left as far as it will go
    temp <<= ((sizeof(int)*8 - n));

    // copy over the value and return it;
    return x | temp;
}

/*
 * Not an exercise from the book, but figure I'll mirror the functionality
 * of the rightrot function
 */
unsigned int leftrot(unsigned int x, int n)
{
    // all those variables are just to make it more readable in righrot...
    return (x << n) | (x >> (sizeof(x) * 8 - n));
}

int main(void)
{
    unsigned int x = 171;               // 10101011
    int y = 170;                        // 10101010 
    int a = setbits(x, 5, 3, y);      
    printf("%d\n", a);                  // 10010011 (147 in base 10)
    
    y = invert(x, 6, 4);            
    printf("%u\n", y);                  // 11010011 (211 in base 10)

    y = rightrot(y, 5);                 // this depends on the size of an int on the
                                        // individual system
    printf("%u\n", y);

    y = leftrot(y, 5);                  // undoing the right rotate, back to 211
    printf("%u\n", y);

    return 0;
}
