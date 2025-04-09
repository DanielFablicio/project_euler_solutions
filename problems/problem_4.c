//Find the largest palindrome made from the product of two 3-digit
//numbers.

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../utils/c_ansi_textstyling.h"

static bool is_palindrome(uint32_t num) {
    uint32_t reversed = 0;
    uint32_t temp = num;
    while (temp != 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    return num == reversed;
}

int main(void) {
    puts(BOLD("PROBLEM 4 - Largest Palindrome Product\n"));
    uint32_t res = 0;

    // Answer is '906609' | Av. Benchmark: 35ms
    for (uint32_t i = 999, k = 999; k >= 91; i--) {
        uint32_t product = k * i;
        if (is_palindrome(product) && product > res)
            res = product;
        if (i == 91) {
            i = 999;
            k--;
        }
    }

    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
