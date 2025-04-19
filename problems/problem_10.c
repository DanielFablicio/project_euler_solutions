// Find the sum of all the primes below two million.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/c_ansi_textstyling.h"

/*
uint64_t sum_of_primes(uint32_t upto) {
    if (upto < 2) return 0;
    if (upto == 2) return 2;

    uint64_t sum = 5; // 2 + 3
    
// First Solution | Av. Benchmark: 396.6ms
    for (uint32_t i = 5; i < upto; i += 2) {
        bool is_prime = true;

        for (uint32_t p = 3; p*p <= i; p += 2) {
            if (i % p == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            sum += i;
    }
//

// Second Solution | Av. Benchmark: 275.3ms
    for (uint32_t i = 5; i < upto; i += 6) {
        for (uint32_t k = 0; k <= 2; k += 2) {
            uint32_t num = i + k;
            if (num >= upto) break;
            
            if (num % 3 != 0) {
                bool is_prime = true;
                for (uint32_t p = 5; p*p <= num; p += 6) {
                    if (num % p == 0 || num % (p+2) == 0) {
                        is_prime = false;
                        break;
                    }
                }
                if (is_prime)
                    sum += num;
            }
        }
    }

    return sum;
}
*/

// Using Sieve of Eratosthenes
uint64_t sum_of_primes(uint32_t upto) {
    uint64_t sum = 0;
    /* Third Solution | Av. Benchmark: 29.3ms
    if (upto < 2) return 0;
    uint32_t mask_size = (upto / 8) + 1;
    uint8_t *bigmask = malloc(mask_size);
    memset(bigmask, 0xFF, mask_size);

    for (uint32_t p = 2; p <= upto; p++)
        if (bigmask[p / 8] & (1 << (p % 8))) {
            sum += p;
            for (uint64_t i = (uint64_t)p*p; i <= upto; i += p)
                bigmask[i / 8] &= ~(1 << (i % 8));   
        }
    */
    uint32_t mask_size = (upto / 8) + 1;
    uint8_t *bigmask = calloc(mask_size, 1);

    for (uint32_t n = 4; n <= upto; n += 2)
        bigmask[n / 8] |= 1 << (n % 8);

    for (uint32_t n = 3; n*n <= upto; n += 2)
        for (uint32_t m = n*n; m <= upto; m += 2*n)
            bigmask[m / 8] |= 1 << (m % 8);

    for (uint32_t n = 2; n <= upto; n++)
        if (!(bigmask[n / 8] & (1 << (n % 8))))
            sum += n;
    free(bigmask);
    return sum;
}

int main(void) {
    puts(BOLD("PROBLEM 10 - Summation of Primes\n"));

    const uint32_t UPTO = 2000000;

    //Answer is '142913828922' | Av. Benchmark: 28.4ms
    uint64_t res = sum_of_primes(UPTO);

    printf("Answer is " FG_HI_GREEN("'%lu'\n"), res);
}
