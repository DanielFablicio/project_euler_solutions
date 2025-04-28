// Which starting number, under one million, produces the longest
// chain(Collatz Sequence)?

#include <stdio.h>
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
    
    //Av. Benchmark: 995.5ms
    u32 res = 0;
    u32 max_terms = 0;
    for (u32 n = 1; n < UPTO; n++) {
        u32 temp = collatz(n);
        if (temp > max_terms) {
            res = n;
            max_terms = temp;
        }
    }
    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
