// There exists exactly one Pythagorean triplet for which
// a + b + c = 1000. Find the product abc.

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../utils/c_ansi_textstyling.h"


// Based on Euclid's formula for generating primitive triples by
// substituting in a + b + c = x
// https://en.wikipedia.org/wiki/Pythagorean_triple
#define EUCLID_SIMPL_FRML(m, n) 2*(m) * ((m) + (n))

typedef
struct {
  uint32_t a;
  uint32_t b;
  uint32_t c;
} PythT;

PythT find_pyth_triangle(uint32_t sum_abc) {
    PythT pyth_triangle;

    uint32_t multiple = 0;
    uint32_t m = 2;
    uint32_t n = 1;

    for (uint32_t i = 1; 2*m*m < sum_abc; i++) {
        uint32_t temp;
        while((temp = EUCLID_SIMPL_FRML(m, n)) < sum_abc) {
            if (sum_abc % temp == 0) {
                multiple = sum_abc / temp;
                break;
            }
            m++;
            n++;
        }
        
        if (multiple) break;
        
        m = 2 + i;
        n = 1;
    }
    // First find the primitive triangle. Now multiply it by `multiple`
    // to get the equivalent triangle such that a+b+c = `sum_abc`.
    pyth_triangle.a = multiple * (m*m - n*n);
    pyth_triangle.b = multiple * (2*m*n);
    pyth_triangle.c = multiple * (m*m + n*n);
    
    return pyth_triangle;
}


int main(void) {
    puts(BOLD("PROBLEM 9 - Special Pythagorean Triplet\n"));

    const uint32_t SUM_ABC = 1000;

    //Answer is '31875000' | Av. Benchmark: < 5ms
    PythT pyth_tr = find_pyth_triangle(SUM_ABC);
    uint32_t res = pyth_tr.a * pyth_tr.b * pyth_tr.c;

    printf("Answer is " FG_HI_GREEN("'%u'\n"), res);
}
