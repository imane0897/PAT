#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int n, m, v, hash[1001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        hash[v]++;
    }

    bool flag = false;
    for (int i = 1; i <= (m-1)/2; i++) {
        if (hash[i] && hash[m-i]) {
            printf("%d %d\n", i, m-i);
            flag = true;
            break;
        }
    }
    if (!flag && m%2 == 0 && hash[m/2] > 1) {
        printf("%d %d\n", m/2, m/2);
        flag = true;
    }

    if (!flag) {
        printf("No Solution\n");
    }
    return 0;
}
