#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct num {
    int add;
    int val;
    int next;
} ;

bool cmp (num a, num b) {
    return a.val < b.val;
}

int main(void) {
    int n, m, i, head_add, b[MAXN] = {0}, c[MAXN] = {0};
    num a[MAXN];

    cin >> n >> head_add;
    for (i = 0; i < n; i++) {
        cin >> a[i].add >> a[i].val >> a[i].next;
        b[a[i].add] = a[i].next;
    }

    while (head_add != -1) {
        c[head_add] = 1;
        head_add = b[head_add];
    }
    m = 0;
    for (i = 0; i < MAXN; i++) {
        if (c[i]) {
            m++;
        }
    }
    sort(a, a+n, cmp);

    cout << m;
    for (i = 0; i < n; i++) {
        if (c[a[i].add]) {
            string res_add = to_string(a[i].add);
            while (res_add.size() < 5)    res_add = "0" + res_add;
            cout << ' ' << res_add << '\n' << res_add << ' ' << a[i].val;
        }
    }
    cout << " -1" << endl;

    return 0;
 }
