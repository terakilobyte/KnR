#include <stdio.h>
#include <ctype.h>

/*
 * Exercise 2-3: Write a function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 */

int hextable[] =
{
    [0 ... 255] = 0,
    ['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    ['A'] = 10, 11, 12, 13, 14, 15,
    ['a'] = 10, 11, 12, 13, 14, 15
};

int htoi(char value[]);

int main(void)
{
    long a, b;

    char first[] = "0X9b7A";
    char second[] = "3FFa4";

    a = htoi(first);
    b = htoi(second);

    printf("%s  == %li\n", first, a);
    printf("%s  == %li\n", second, b);
    
    return 0;
}

int htoi(char hex[])
{
    int i;
    long answer = 0;
    for (i = 0; hex[i] != '\0' && answer >= 0; i++)
    {
        answer = (answer << 4) | hextable[hex[i]];
    }

    return answer;
}
