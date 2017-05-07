#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int g1, g2, g3, s1, s2, s3, k1, k2, k3;

    scanf("%d", &g1);
    getchar();
    scanf("%d", &s1);
    getchar();
    scanf("%d", &k1);
    getchar();

    scanf("%d", &g2);
    getchar();
    scanf("%d", &s2);
    getchar();
    scanf("%d", &k2);
    getchar();

    k3 = k1 + k2;
    s3 = s2 + s1 + k3 / 29;
    k3 = k3 % 29;
    g3 = g1 + g2 + s3 / 17;
    s3 = s3 % 17;

    printf("%d.%d.%d\n", g3, s3, k3);

    return 0;
}
