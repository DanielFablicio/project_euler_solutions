//What is the largest prime factor of the number 600851475143?

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../utils/c_ansi_textstyling.h"

static uint64_t largest_factor(uint64_t num) {
    bool is_odd = num % 2 != 0;
    uint64_t factor = 2;
    uint64_t add = 1;

    if (is_odd) {
        factor = 3;
        add = 2;
    }

    while (num > 1) {
        if (num % factor != 0) {
            for (uint64_t f = factor + add; f <= num; f += add) {
                if (num % f == 0) {
                    factor = f;
                    break;
                }
            }
        }
        num /= factor;
    }
    return factor;
}

int main(void) {
    puts(BOLD("PROBLEM 3 - Largest Prime Factor\n"));

    const uint64_t NUMBER = 600851475143;

    //Answer is 6857
    uint64_t res = largest_factor(NUMBER);

    printf("Answer is " FG_HI_GREEN("'%lu'\n"), res);
}
