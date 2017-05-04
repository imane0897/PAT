#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 105;


int main(void) {
    int N, M, i;
    int level[MAXN];
    int index[MAXN];
    int count[MAXN];
    bool flag[MAXN];

    for(i = 0; i < MAXN; i++) {
        level[i] = 0;
        flag[i] = true;
        index[i] = i;
        count[i] = 0;
    }
    level[1] = 1;

    scanf("%d%d", &N, &M);
    int id, k, k_id;
    for (i = 0; i < M; i++) {
        scanf("%d%d", &id, &k);
        flag[id] = false;
        for (int j = 0; j < k; j++) {
            scanf("%d", &k_id);
            if (level[id] <= 0) {
                continue;
            } else {
            level[k_id] = level[id] + 1;
            }
        }
    }

    for (i = 1; i <= N; i++) {
        if (flag[i]) {
            count[level[i]] += 1;
        }
    }

    int sum = 0;
    for (i = 1; i <= N; i++) {
        printf("%d", count[i]);
        sum += count[i];
        if (sum != N - M) {
            printf(" ");
        } else {
            break;
        }
    }
    printf("\n");

    return 0;
}
