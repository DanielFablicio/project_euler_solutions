// What is the value of the first triangle number to have over 500
// divisors?

#include <stdio.h>
#include "../utils/c_ansi_textstyling.h"
#include "../utils/custom_types.h"
#include "../utils/utils.h"

static inline u64 tri_number(u32 n) {
    return ((1+n)*n)/2;
}

// Based on slide 6 of the presentation: 
// https://www.canaleducacao.tv/images/slides/43704_9d2dee86cb4694c9c50bdf06302ccf43.pdf
static u32 divisors_num(u64 n) {
    if (!n) return 1;
    
    u32 dv_num = 1;
    u32 cnt_mult = 0;

    for (u32 f = 2; f <= 3; f++) {
        cnt_mult = 0;
        while (n % f == 0) {
            n /= f;
            cnt_mult++;
        }
        dv_num *= cnt_mult+1;
    }
    
    for (u32 k = 1; n != 1; k++) {
        for (u32 f = 6*k-1, i = 0; i < 2; f += 2, i++) {
            cnt_mult = 0;
            while (n % f == 0) {
                n /= f;
                cnt_mult++;
            }
            dv_num *= cnt_mult+1;
        }
    }
    return dv_num;
}

u64 high_div_tri_number(u32 dv_num) {
    u64 num = 1;
    for (u32 k = 2; divisors_num(num) < dv_num; (num=tri_number(k)), k++);
    return num;
}


int main(void) {
    puts(BOLD("PROBLEM 12 - Highly Divisible Triangular Number\n"));

    #define DIVISORS_NUM 500
    //Answer is '76576500' | Av. Benchmark: 149.1ms
    u64 res = high_div_tri_number(DIVISORS_NUM);
    printf("Answer is " FG_HI_GREEN("'%lu'\n"), res);
}
