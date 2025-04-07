//Find the sum of all the multiples of 3 or 5 below 1000
#include <stdio.h>
#include "../utils/c_ansi_textstyling.h"

int main() {
    puts(BOLD("PROBLEM 1 - Multiples of 3 or 5\n"));
    const int NUM_1 = 3;
    const int NUM_2 = 5;
    const int MAX_NUM = 1000;

    int res = 0;
    for (int i = 0; i < MAX_NUM; i++) {
        if (i % NUM_1 == 0 || i % NUM_2 == 0)
            res += i;
        }

    printf("Answer is " FG_HI_GREEN("'%d'\n"), res);
}
