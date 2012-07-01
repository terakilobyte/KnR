#include <stdio.h>

/*
 * This is a solution to exercise 1-16 from K&R.  Its' aim
 * is to read input line by line, comparing the line lengths
 * and printing out the length and the line text at end of input.
 */

#define MAXLINE 1000 // the maximum allowable line size

int getline16(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline16(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return  0;
}

int getline16(char line[], int maxline)
{
    int c, i;
    
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
