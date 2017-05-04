#include <iostream>
#include <array>
#include <climits>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 505;
int cost[MAXN][MAXN];
int path_2_des[MAXN];         // number of paths from element i to element des
int path_cost[MAXN];          // cost of element i to element j

void find_all_path() {

}

int main(void) {
    int m, n, c1, c2, ca, cb, rlength, max_hands;
    int team[MAXN] = {0};

    memset(cost, -1, sizeof(cost));           // -1 means not accessible

    scanf("%d%d%d%d", &m, &n, &c1, &c2);
    for (int i = 0; i < m; i++) {
        scanf("%d", &team[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &ca, &cb, &rlength);
        cost[ca][cb] = rlength;
        cost[cb][ca] = rlength;
    }




    // printf("%d %d\n", , max_hands);
    return 0;
}
