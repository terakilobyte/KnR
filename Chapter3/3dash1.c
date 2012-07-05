#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define SIZE 75000

/*
 * Exercise 3-1.  Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside).  Write 
 * a version with only one test inside the loop at measure the difference
 * in runtime.
 */

/* binsearch:  find x in v[0] <= v[1] ... <=v[n-1] */
int binsearchknr(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; /* no match */
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high)
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    return (v[mid] == x) ? mid : -1;
}

int main(void)
{
    int test[SIZE];
    int position;
    int toBeFound = SIZE + 1; //won't be found
    clock_t begin;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        test[i] = i;
    }

    //50,000 iterations should give us something measurable
    for (i = 0, begin = clock(); i < 50000; i++)
    {
        position = binsearchknr(toBeFound, test, SIZE);
    }
    printf("Runtime for original binsearch for 50,000 iterations is %f\n", ((double)clock() - begin) / CLOCKS_PER_SEC);

    for(i = 0, begin = clock(); i < 50000; i++)
    {
        position = binsearch(toBeFound, test, SIZE);
    }
    printf("Runtime for new binsearch for 50,000 iterations is %f\n", ((double)clock() - begin) / CLOCKS_PER_SEC);
}
