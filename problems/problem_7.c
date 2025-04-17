//Find the 10001st prime number

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../utils/c_ansi_textstyling.h"

static bool is_prime(uint32_t num) {
    if (num < 2 || (num != 2 && num % 2 == 0))
        return false;

    for (uint32_t i = 3; i*i <= num; i += 2)
        if (num % i == 0)
            return false;
    return true;
}

static uint32_t prime(uint32_t n) {
    if (n <= 1) return 2;
    uint32_t prime = 3;
    uint32_t i = 2;
    for (; i < n; i++) {
        while (!is_prime((prime += 2)));
    }
    
    return prime;
}

int main(void) {
    puts(BOLD("PROBLEM 7 - 10 001st Prime\n"));
    
    const uint32_t PRIME_N = 10001;
    
    //Answer is '104743' | Av. Benchmark: 9.3ms
    uint32_t res = prime(PRIME_N);

    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
