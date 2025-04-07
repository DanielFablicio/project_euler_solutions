//Find the sum of all the multiples of 3 or 5 below 1000

#include <stdio.h>
#include "../utils/c_ansi_textstyling.h"

int main() {
    puts(BOLD("PROBLEM 1 - Multiples of 3 or 5\n"));
    const int NUM_1 = 3;
    const int NUM_2 = 5;
    const int MAX_NUM = 1000;

    int res = 0;
    /* First solution [ O(n) ] Answer = 233168
    for (int i = 0; i < MAX_NUM; i++) {
        if (i % NUM_1 == 0 || i % NUM_2 == 0)
            res += i;
        } */

    // Second solution [O(1)]
    #define AP(n1, nl, count) ((n1) + (nl)) * (count) / 2

    res = AP(1, (MAX_NUM-1) / NUM_1, (MAX_NUM-1) / NUM_1) * NUM_1 +
          AP(1, (MAX_NUM-1) / NUM_2, (MAX_NUM-1) / NUM_2) * NUM_2 -
          AP(1, (MAX_NUM-1) / (NUM_1*NUM_2), (MAX_NUM-1) / (NUM_1*NUM_2)) * (NUM_1*NUM_2);


    printf("Answer is " FG_HI_GREEN("'%d'\n"), res);
}
