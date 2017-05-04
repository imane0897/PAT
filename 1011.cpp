#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    double a[3][3], product = 1, m;
    int i, j, flag;
    char c;

    for (i = 0; i < 3; i++) {
        m = 0;
        for (j = 0; j < 3; j++) {
            scanf("%lf", &a[i][j]);
            if (m < a[i][j]) {
                m = a[i][j];
                flag = j;
            }
        }
        product *= m;
        switch (flag) {
            case 0: c = 'W'; break;
            case 1: c = 'T'; break;
            case 2: c = 'L'; break;
        }
        printf("%c ", c);
    }
    product = (product * 0.65 - 1) * 2;
    printf("%.2lf\n", product);

    return 0;
}
