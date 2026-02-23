#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double f(double x) {
    return -x * x + 4 * x;
}

void hill_climb(double *best_x, double *best_val) {
    double x;
    double step = 0.3;

    
    srand(time(NULL));

    x = -10 + ((double)rand() / RAND_MAX) * 20;

    while (1) {
        if (f(x + step) > f(x)) {
            x = x + step;
        } 
        else if (f(x - step) > f(x)) {
            x = x - step;
        } 
        else {
            break;
        }
    }

    *best_x = x;
    *best_val = f(x);
}

