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

int main() {
    double x, val;

    hill_climb(&x, &val);

    printf("Best Solution (x): %.4lf\n", x);
    printf("Maximum Value f(x): %.4lf\n", val);

    return 0;
}

// output
// Best Solution (x): 2.0000
// Maximum Value f(x): 4.0000
