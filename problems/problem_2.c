//By considering the terms in the Fibonacci sequence whose values do
//not exceed four million, find the sum of the even-valued terms.

#include <stdio.h>
#include <stdint.h>
#include "../utils/c_ansi_textstyling.h"

static uint32_t fibonacci(uint32_t n_term) {
    uint32_t res = 0;
    uint32_t temp = 1;

    for (uint32_t i = 0; i < n_term; i++) {
        res += temp;
        temp = res - temp;
    }

    return res;
}

int main() {
    puts(BOLD("PROBLEM 2 - Even Fibonacci Numbers\n"));

    const uint32_t MAX_VALUE = 4000000;

    //Answer is 4613732
    uint32_t res = 0;
    for (int i = 1;; i++) {
        uint32_t fib = fibonacci(i);
        if (fib > MAX_VALUE)
            break;
        if (fib % 2 != 0)
            continue;
        res += fib;
    }

    printf("Answer is " FG_HI_GREEN("'%d'\n"), res);
}
