#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int main(void) {
    int add1_beg, add2_beg;
    int add1, add2, n, i, j;
    int add_vis[MAXN] = {0}, add[MAXN] = {0};
    char c;

    scanf("%d%d%d", &add1_beg, &add2_beg, &n);
    for (i = 0; i < n; i++) {
        scanf("%d %c %d", &add1, &c, &add2);
        add[add1] = add2;
    }

    while (add1_beg != -1) {
        add_vis[add1_beg] = 1;
        add1_beg = add[add1_beg];
    }
    while (add2_beg != -1) {
        if (add_vis[add2_beg])    break;
        add2_beg = add[add2_beg];
    }

    if (add2_beg == -1) {
        cout << "-1" << endl;
    }
    else {
        string output = to_string(add2_beg);
        while (output.size() < 5) {
            output = "0" + output;
        }
        cout << output << endl;
    }
    return 0;
}
