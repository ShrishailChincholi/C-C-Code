#include <stdio.h>

int trap(int* h, int n) {
    int l = 0, r = n - 1;
    int ml = 0, mr = 0, water = 0;

    while (l < r) {
        if (h[l] < h[r]) {
            h[l] >= ml ? (ml = h[l]) : (water += ml - h[l]);
            l++;
        } else {
            h[r] >= mr ? (mr = h[r]) : (water += mr - h[r]);
            r--;
        }
    }
    return water;
}

int main() {
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(h) / sizeof(h[0]);
    printf("Water trapped: %d\n", trap(h, n));
    return 0;
}