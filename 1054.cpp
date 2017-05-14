#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 250000;
int f[MAX] = {0}, g[MAX] = {0};

int hash2(int k) {
    int t = k % MAX;
    if (t < 0)    t += MAX;
    while (g[t] != k && f[t] != 0) {
        t = (t+1) % MAX;
    }
    return t;
}

int main(void) {
    int m, n, x, p;
    
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m * n; i++) {
        scanf("%d", &x);
        p = hash2(x);
        g[p] = x;
        f[p]++;
    }

    int max = 0, domin = 0;
    for (int i = 0; i < MAX; i++) {
        if (f[i] > max) {
            max = f[i];
            domin = g[i];
        }
    }
    printf("%d\n", domin);
    return 0;
}
