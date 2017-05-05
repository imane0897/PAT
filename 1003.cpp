#include <iostream>
#include <array>
#include <climits>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 505;
const int INF = 0x3f3f3f;
bool vis[MAXN];
int pre[MAXN];
int path_count[MAXN];

void Dijkastra(const int cost[][MAXN], int lowcost[], int n, int beg) {
    for (int i = 0; i < n; i++) {
        lowcost[i] = INF; vis[i] = false; pre[i] = -1; path_count[i] = 0;
    }
    lowcost[beg] = 0;
    for (int j = 0; j < n; j++) {
        int k = -1;
        int Min = INF;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && lowcost[i] < Min) {
                Min = lowcost[i];
                k = i;
            }
        }
        if (k == -1) break;
        vis[k] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i]){
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            } else if (!vis[i] && lowcost[k] + cost[k][i] == lowcost[i] && k != beg) {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
                printf("lowcost[%d] = %d, cost[%d][%d] = %d, lowcost[%d] = %d\n", k, lowcost[k], k, i, cost[k][i], i, lowcost[i]);
                path_count[i]++;
            }
        }
    }
}


int main(void) {
    int n_city, n_path, beg_city, des_city;
    int team[MAXN], cost[MAXN][MAXN], lowcost[MAXN];
    int sum = 0;

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            cost[i][j] = INF;
        }
    }

    // input
    scanf("%d%d%d%d", &n_city, &n_path, &beg_city, &des_city);
    for (int i = 0; i < n_city; i++) {
        scanf("%d", &team[i]);
    }
    int c1, c2, l;
    for (int i = 0; i < n_path; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        cost[c1][c2] = l;
        cost[c2][c1] = l;
    }
    //////

    if (beg_city == des_city) {
        printf("1 %d\n", team[beg_city]);
        return 0;
    }

    Dijkastra(cost, lowcost, n_city, beg_city);

    int j = des_city;
    while (pre[j] != -1) {
        sum += team[j];
        j = pre[j];
    }
    sum += team[beg_city];

    // output
    printf("%d %d\n", path_count[des_city] + 1, sum);
    //////

    return 0;
}
