#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

bool cmp(int i, int j) {return i > j;}

int main(void) {
    int n1, n2, nc_pos[MAXN], nc_neg[MAXN], np_pos[MAXN], np_neg[MAXN];
    int money = 0;
    int i, t;

    memset(nc_pos, 0, MAXN);
    memset(np_pos, 0, MAXN);
    memset(np_neg, 0, MAXN);
    memset(np_neg, 0, MAXN);

    scanf("%d", &n1);
    int nc_p = 0, nc_q = 0;
    for (i = 0; i < n1; i++) {
        scanf("%d", &t);
        if (t > 0) {
            nc_pos[nc_p++] = t;
        } else if (t < 0) {
            nc_neg[nc_q++] = t;
        }
    }
    scanf("%d", &n2);
    int np_p = 0, np_q = 0;
    for (i = 0; i < n2; i++) {
        scanf("%d", &t);
        if (t > 0) {
            np_pos[np_p++] = t;
        } else if (t < 0) {
            np_neg[np_q++] = t;
        }
    }

    sort(nc_pos, nc_pos + nc_p, cmp);
    sort(nc_neg, nc_neg + nc_q);
    sort(np_pos, np_pos + np_p, cmp);
    sort(np_neg, np_neg + np_q);

    money = 0;
    for (i = 0; i < nc_p && i < np_p; i++) {
        money += nc_pos[i] * np_pos[i];
    }
    for (i = 0; i < nc_q && i < np_q; i++) {
        money += nc_neg[i] * np_neg[i];
    }

    printf("%d\n", money);
    return 0;
}
