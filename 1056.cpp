#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1010;

struct mouse {
    int weight;
    int order;
    int index;
    int rank;
    bool lose;
} ;

bool cmp1(mouse a, mouse b) {
    return a.order < b.order;
}

bool cmp2(mouse a, mouse b) {
    return a.index < b.index;
}

int main(void) {
    int n, gsize, i, j;
    mouse a[MAX];

    scanf("%d%d", &n, &gsize);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i].weight);
        a[i].index = i;
        a[i].lose = false;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &j);
        a[j].order = i;
    }

    sort(a, a+n, cmp1);
    int n2 = n, th;
    while (n2 > 1){
        if (n2 % gsize)    th = 1;
        else th = 0;
        n2 = n2 / gsize + th;
        th = n2 + 1;
        // cout << n2 << endl;

        int count = 0, max = -1, max_i = -1;
        for (i = 0; i < n; i++) {
            if (!a[i].lose) {
                count++;
                if (a[i].weight < max) {
                    a[i].lose = true;
                    a[i].rank = th;
                } else {
                    if (max_i != -1) {
                        a[max_i].lose = true;
                        a[max_i].rank = th;
                    }
                    max_i = i;
                    max = a[i].weight;
                }
            }
            if (count >= gsize) {
                max = -1;
                max_i = -1;
                count = 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (!a[i].lose) {
            a[i].rank = 1;
        }
    }

    sort(a, a+n, cmp2);
    for (i = 0; i < n - 1; i++) {
        printf("%d ", a[i].rank);
    }
    printf("%d\n", a[i].rank);
    return 0;
}
