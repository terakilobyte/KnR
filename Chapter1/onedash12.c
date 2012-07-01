#include <stdio.h>
/*
 * This program reads input from the terminal (after launch) and puts
 * each word on its' own line.
 */

int main(int argc, char *argv[])
{
    int c, tab, space, newLine;

    while((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }

    printf("%d", 'a');

    return 0;
}
