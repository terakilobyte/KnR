#include <stdio.h>
#include <ctype.h>

/*
 * Exercise 2-4:  Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character s2.
 *
 * for every character in s1;
 * compare it against every character in s2;
 * if it matches, remove it
 */

#define false 0
#define true 1

void squeeze(char s1[], char s2[]);

int main(void)
{
    char a[] = "wqTzhixvvs sqzhvxouxlqd mzaqkxe szeqnsxqez sqwowzqxon!";
    char b[] = "wqzxv";

    squeeze(a, b);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int matched;
    char toPrint[1000];
    k = 0;

    for (i = 0; s1[i] != '\0';i++)
    {
        matched = false;

        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                matched = true;
            }

        }

        if (!matched)
        {
            toPrint[k++] = s1[i];
        }
    }
    toPrint[k] = '\0';

    printf("%s\n", toPrint);
}
