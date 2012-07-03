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

    printf("%s\n", a);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    int z = 0;
    
    // for every element in s1
    for (i = 0; s1[i] != '\0';i++)
    {
        // for every element in s2
        for (j = 0; s2[j] != '\0'; j++)
        {   // if the element in s1 at position i matches s2
            if (s1[i] == s2[j])
            {
                break;
            }
        }

        // if there were no matches for position i against s2
        if (s2[j] == '\0')
        {
            //The element in s1 at z is now set to wherever i is in the sentence
            //and then increment z
            s1[z++] = s1[i];
        }
    }

    s1[z] = '\0';
}

