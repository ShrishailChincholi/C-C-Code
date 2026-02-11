#include <stdio.h>

int main() {
    int n = 5;

    for (int i = n; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}

// output
// *********
//  *******
//   *****
//    ***
//     *


#include <stdio.h>

int main() {
    int n = 4;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}


// output
//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf("  ");
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}


// Output
//         * 
//       * * 
//     * * * 
//   * * * * 
// * * * * * 



#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

// Output
// * * * * * 
// *       * 
// *       * 
// *       * 
// * * * * * 


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

// Output
// *       *
//   *   *
//     *
//   *   *
// *       *


#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2*i - 1; j++) {
            if (j == 1 || j == 2*i - 1 || i == n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

// Output
//     *
//    * *
//   *   *
//  *     *
// *********
