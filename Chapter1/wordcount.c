#include <stdio.h>

#define IN 1 /*Inside a word*/
#define OUT 0 /*Outside a word*/

int main(int argc, char *argv[]) {
    int c = nc = word = line = 0;

    state = OUT;

    while ((c = getchar()) != EOF) {

        if (c == '\n') {
            line++;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = out;
        }
        else if (state == OUT) {
            state = IN;
            word ++;
        }
