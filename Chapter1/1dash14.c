#include <stdio.h>

/*
 * This is a solution to K&R exercise 1-14, printing a histogram
 * of the various characters given as input to the program
 */

#define ASCIICHARS 128

int main(int argc, char *argv[])
{
    int c;
    // I'm making this as the zero char to convert
    // the other inputs to their int values
    
    char inputs[ASCIICHARS] = {0};

    while ((c = getchar()) != EOF)
    {
        inputs[c - '']++;
    }

    int curr, max, i, j;
    max = 0;

    for (i = 0; i < ASCIICHARS; i++)
    {
        //as long as it's no 0
        if (inputs[i])
        {
            printf("%1c", inputs[i]);
        }
    }

    printf("%c", 0);
    return 0;
}

