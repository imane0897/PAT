#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int n, m, i, j, beg, des;
    int a[100010] = {0};
    int dis1, dis2;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    dis1 = 0;
    for (i = 1; i < n; i++) {
        dis1 += a[i];
        a[i] = dis1;
    }

    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        scanf ("%d %d", &beg, &des);
        if (des < beg)  swap(des, beg);
        // clockwise
        dis1 = a[des - 1] - a[beg - 1];

        // counterclockwise
        dis2 = a[beg - 1] + a[n] + a[n - 1] - a[des - 1];

        if (dis1 < dis2)    printf("%d\n", dis1);
        else    printf("%d\n", dis2);
    }

    return 0;
}
