#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 501;
const int INF = 0x3f3f3f3f;
int num[MAXN];
int cost[MAXN][MAXN];
int lowcost[MAXN];
bool vis[MAXN];
int w[MAXN];
int v[MAXN];

void Dijkstra(int n, int beg) {
    for (int i = 0; i < n; i++) {
        lowcost[i] = INF;  vis[i] = false; num[i] = 0;
    }
    lowcost[beg] = 0;
    num[beg] = 1;
    w[beg] = v[beg];
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
                num[i] = num[k];
                w[i] = v[i] + w[k];
            } else if (!vis[i] && lowcost[k] + cost[k][i] == lowcost[i]) {
                if (v[i] + w[k] > w[i]) {
                    w[i] = v[i] + w[k];
                    lowcost[i] = lowcost[k] + cost[k][i];
                }
                num[i] += num[k];
            }
        }
    }
}

int main() {
    int N, M, C1, C2, i, j, l;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cost[i][j] = INF;
        }
    }
    for (int k = 0; k < M; k++) {
        scanf("%d %d %d", &i, &j, &l);
        cost[i][j] = l;  cost[j][i] = l;
    }
    Dijkstra(N, C1);

    printf("%d %d\n", num[C2], w[C2]);
    return 0;
}
