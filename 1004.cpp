#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[100];
int book[100];
int maxlevel = 0;

void dfs(int node, int level) {
    if (v[node].empty()) {
        book[level]++;
        maxlevel = max(level, maxlevel);
        return ;
    }
    for (size_t i = 0; i < v[node].size(); i++) {
        dfs(v[node][i], level + 1);
    }
}

void bfs() {
    int level[100];
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (!q.empty()) {
        int index = q.front();
        maxlevel = max(level[index], maxlevel);
        q.pop();
        if (v[index].size() == 0) {
            book[level[index]]++;
        }
        for (size_t i = 0; i < v[index].size(); i++) {
            q.push(v[index][i]);
            level[v[index][i]] = level[index] + 1;
        }
    }
}

int main() {
    int N, M, node, child, k;
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d", &node, &k);
        while (k--) {
            scanf("%d", &child);
            v[node].push_back(child);
        }
    }

    // dfs(1, 0);
    bfs();
    for (int i = 0; i < maxlevel; i++) {
        printf("%d ", book[i]);
    }
    printf("%d\n", book[maxlevel]);
    return 0;
}
