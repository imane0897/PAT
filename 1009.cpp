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

poly a[15], b[15];


int main(void) {
    int k1, k2, i, j;
    double c[2010] = {0};

    // init
    for (i = 0; i < 15; i++) {
        a[i].expo = 0; a[i].coe = 0;
        b[i].expo = 0; b[i].coe = 0;
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
            c[expo] += coe;
        }
    }

    int count = 0;
    for (i = 0; i < 2010; i++) {
        if (abs(c[i]) != 0) {
            count++;
        }
    }
    // std::sort(c, c+100, mysortfunc);

    // output
    printf("%d", count);
    for (i = 2010 - 1; i >= 0; i--) {
        if (abs(c[i]) != 0) {
            printf(" %d %.1lf", i, c[i]);
        }
    }
    printf("\n");
    //////
    return 0;
}
