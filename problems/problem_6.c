//Find the difference between the sum of the squares of the first one
//hundred natural numbers and the square of the sum.

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../utils/c_ansi_textstyling.h"

#define AP(n1, nl, count) ((n1) + (nl)) * (count) / 2

static uint32_t sum_of_squares(uint32_t start_num, uint32_t end_num) {
    uint32_t res = 0;
    for (uint32_t i = start_num; i <= end_num; i++)
        res += i * i;
    return res;
}

static uint32_t square_of_sum(uint32_t start_num, uint32_t end_num) {
    uint32_t res = AP(start_num, end_num, end_num - start_num + 1);
    return res * res;
}

int main(void) {
    puts(BOLD("PROBLEM 6 - Sum Square Difference\n"));

    const uint32_t START_NUM = 1;
    const uint32_t END_NUM = 100;

    //Answer is '25164150' | Av. Benchmark: < 5ms
    uint32_t res = square_of_sum(START_NUM, END_NUM) -
                  sum_of_squares(START_NUM, END_NUM);

    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
