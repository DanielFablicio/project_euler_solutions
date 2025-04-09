//What is the smallest positive number that is evenly divisible by all
//of the numbers from 1 to 10?

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../utils/c_ansi_textstyling.h"

// LCM(Least Common Multiple) implementation based on the article at:
// https://www.blogcyberini.com/2018/03/algoritmo-para-calcular-o-mmc.html
static uint32_t gcd(uint32_t a, uint32_t b) {
    while (b != 0) {
        uint32_t temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

static uint32_t lcm(uint32_t a, uint32_t b) {
    return a * (b / gcd(a, b));
}

int main(void) {
    puts(BOLD("PROBLEM 5 - Smallest Multiple\n"));

    const uint32_t START_NUM = 1;
    const uint32_t END_NUM = 20;

    //Answer is '232792560' | Av. Benchmark: < 5ms
    uint32_t res = lcm(START_NUM, START_NUM+1);
    for (uint32_t i = START_NUM+2; i < END_NUM; i++)
        res = lcm(res, i);

    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
