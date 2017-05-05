#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void) {
    int n1, n2, nc[100010], np[100010];
    long long int money = 0;
    int i;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &nc[i]);
    }
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &np[i]);
    }

    sort(nc, nc + n1);
    sort(np, np + n2);

    int bonus;
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
            bonus = nc[i] * np[n2 - (n2 - n1) + i];
            if (bonus > 0) {
                money += bonus;
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
            bonus = nc[i] * np[i - (n2 - n1)];
            if (bonus > 0) {
                money += bonus;
            }

        }
    }
    printf("%lld\n", money);
    return 0;
}
