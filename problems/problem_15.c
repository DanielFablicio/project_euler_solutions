// How many such routes are there through a 20x20 grid?

#include <stdio.h>
#include "../utils/c_ansi_textstyling.h"
#include "../utils/custom_types.h"
#include "../utils/utils.h"

static double factorial(u32 num, u32 cut) {
    if (cut > num)
        return 0;
    double res = 1.0;
    for (u32 i = num; i > cut; i--)
        res *= i;
    return res;
}

double lattice_paths(u32 rows, u32 cols) {
    u32 max = rows > cols ? rows : cols;
    return factorial(rows + cols, max) / factorial(cols, 0);
}

int main(void) {
    puts(BOLD("PROBLEM 15 - Lattice Paths\n"));

    #define ROWS 20
    #define COLS 20
    
    // Av. Benchmark: < 5ms
    double res = lattice_paths(ROWS, COLS);
    
    printf("Answer is " FG_HI_GREEN("'%0.f'\n"), res);
}
