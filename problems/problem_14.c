// Which starting number, under one million, produces the longest
// chain(Collatz Sequence)?

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/c_ansi_textstyling.h"
#include "../utils/custom_types.h"
#include "../utils/utils.h"

u32 collatz(u32 n) {
    u32 n_terms = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3*n + 1;
        n_terms++;
    }
    return n_terms;
}

int main(void) {
    puts(BOLD("PROBLEM 14 - Longest Collatz Sequence\n"));

    #define UPTO 1000000
    
    u32 res = 0;
    u32 max_terms = 0;
    // 1º Solution | Av. Benchmark: 331.5ms (-O1)
    // for (u32 n = 1; n < UPTO; n++) {
    //     u32 temp = collatz(n);
    //     if (temp > max_terms) {
    //         res = n;
    //         max_terms = temp;
    //     }
    // }

    // Av. Benchmark: 176.6ms
    u16 *savefield = calloc(UPTO/2, sizeof(u16));
    if (!savefield)
        die("Error in memory allocation!");
    for (u32 n = UPTO / 2; n < UPTO; n++) {
        u32 temp = 0;
        u32 num = n;
        if (num % 2 != 0) {
            num = 3*num+1;
            temp++;
        }
        while(num % 2 == 0) {
            num /= 2;
            temp++;
        }
        bool can_save = num < UPTO/2;
        if (can_save && savefield[num] != 0)
            temp += savefield[num];
        else {
            u32 cltz = collatz(num);
            if (can_save)
                savefield[num] = cltz;
            temp += cltz;
        }
        if (temp > max_terms) {
            res = n;
            max_terms = temp;
        }
    }
    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
    free(savefield);
}
