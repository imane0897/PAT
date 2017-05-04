#include <iostream>
#include <stdio.h>
#include <array>
#include <cstring>
using namespace std;

int main(void) {
    int k, i, j, index, max_index = 0;
    double a[1005], b[1005], c[1005];

    memset(a, 0, 1005);
    memset(b, 0, 1005);
    memset(c, 0, 1005);

    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d", &index);
        scanf("%lf", &a[index]);
        if (index > max_index) {
            max_index = index;
        }
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d", &index);
        scanf("%lf", &b[index]);
        if (index > max_index) {
            max_index = index;
        }
    }

    for (i = 0; i <= max_index; i++) {
        for (j = 0; j<= max_index; j++) {
            index = i + j;
            c[index] += a[i] * b[j];
        }
    }

    int count = 0;
    for (i = 0; i <= 2*max_index; i++) {
        if (c[i] > 0.001) {
            count ++;
        }
    }

    // output
    printf("%d", count);
    for (i = max_index; i >= 0; i--) {
        if (c[i] > 0.001) {
            printf(" %d", i);
            printf(" %.1lf", c[i]);
        }
    }
    printf("\n");
    return 0;
}
