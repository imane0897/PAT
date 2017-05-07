#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

bool cmp(int i, int j) {return i > j;}

int main(void) {
    int n1, n2, nc[MAXN], np[MAXN];
    int money = 0;
    int i;

    memset(nc, 0, MAXN);
    memset(np, 0, MAXN);

    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &nc[i]);
    }
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &np[i]);
    }

    sort(nc, nc + n1, cmp);
    sort(np, np + n2, cmp);

    int bonus = -1;
    if (n1 == n2) {
        for (i = 0; i < n1; i++) {
            bonus = nc[i] * np[i];
            if (bonus > 0) {
                money += bonus;
            }
        }
    } else if (n1 > n2) {
        for (i = 0; i < n2; i++) {
            bonus = nc[i] * np[i];
            if (bonus > 0) {
                money += bonus;
            }
        }
        for (i = n2; i < n1; i++){
            if (0<= i - (n1 - n2) && i - (n1 - n2) < n2) {
                bonus = nc[i] * np[i - (n1 - n2)];
                if (bonus > 0) {
                    money += bonus;
                }
            }
        }
    } else if (n2 > n1) {
        for (i = 0; i < n1; i++) {
            bonus = nc[i] * np[i];
            if (bonus > 0) {
                money += bonus;
            }
        }
        for (i = n1; i < n2; i++){
            if (0 <= i - (n2 - n1) && i - (n2 - n1) < n1) {
                bonus = nc[i - (n2 - n1)] * np[i];
                if (bonus > 0) {
                    money += bonus;
                }
            }
        }
    }
    printf("%d\n", money);
    return 0;
}
