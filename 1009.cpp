#include <iostream>
#include <stdio.h>
#include <array>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct poly {
    int expo;
    double coe;
} ;

poly a[15], b[15], c[100];
int flag = -1;

void refresh_c(int expo, double coe) {
    for (int i = 0; i < 100; i++) {
        if (c[i].expo == expo) {
            c[i].coe += coe;
            return;
        }
    }
    c[++flag].expo = expo;
    c[flag].coe = coe;
}

bool mysortfunc(const poly a, const poly b) {
    if (a.expo > b.expo) {
        return true;
    }
    return false;
}


int main(void) {
    int k1, k2, i, j;

    // init
    for (i = 0; i < 15; i++) {
        a[i].expo = 0; a[i].coe = 0;
        b[i].expo = 0; b[i].coe = 0;
    }
    for (i = 0; i < 100; i++) {
        c[i].expo = 0; c[i].coe = 0;
    }
    //////

    // input
    scanf("%d", &k1);
    for (i = 0; i < k1; i++) {
        scanf("%d%lf", &a[i].expo, &a[i].coe);
    }
    scanf("%d", &k2);
    for (i = 0; i < k2; i++) {
        scanf("%d%lf", &b[i].expo, &b[i].coe);
    }
    //////

    int expo;
    double coe;
    for (i = 0; i < k1; i++) {
        for (j = 0; j < k2; j++) {
            expo = a[i].expo + b[j].expo;
            coe = a[i].coe * b[j].coe;
            refresh_c(expo, coe);
        }
    }

    int count = 0;
    for (i = 0; i < 100; i++) {
        if (abs(c[i].coe) > 0.005) {
            count++;
        }
    }
    std::sort(c, c+100, mysortfunc);

    // output
    printf("%d", count);
    for (i = 0; i < 100; i++) {
        if (abs(c[i].coe) > 0.005) {
            printf(" %d %.1lf", c[i].expo, c[i].coe);
        }
    }
    printf("\n");
    //////
    return 0;
}
