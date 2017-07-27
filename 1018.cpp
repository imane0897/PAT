#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 501;
int cost[MAXN][MAXN];
int lowcost[MAXN];
bool vis[MAXN];
int send[MAXN];
int take[MAXN];
int pre[MAXN];
int v[MAXN];

void Dijkstra(int n, int beg) {
    for (int i = 0; i < n ; i++) {
        lowcost[i] = INF;  vis[i] = false;  pre[i] = -1;
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
        if (k == -1)  break;
        vis[k] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i]) {
                lowcost[i] = lowcost[k] + cost[k][i];
                pre[i] = k;
            } else if (!vis[i] && lowcost[k] + cost[k][i] == lowcost[i]) {

            }
        }
    }
}

int main() {
    int Cmax, N, Sp, M;
    fill(cost[0], cost[0] + MAXN * MAXN, INF);
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    int Si, Sj, l;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &Si, &Sj, &l);
        cost[Si][Sj] = l;  cost[Sj][Si] = l;
    }
    Dijkstra(N, Sp);
    return 0;
}
