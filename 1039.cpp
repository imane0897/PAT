#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200000;
vector<int> f[MAX];

int hash2(char *s) {
    int i, t = 0;
    for (i = 0; i < 3; i++) {
        t = 26 * t + (s[i] - 'A');
    }
    t = t * 10 + s[i] - '0';
    return t;
}

int main(void) {
    int n, k, i, j, course, num_stu, p;
    char name[5];

    scanf("%d%d", &n, &k);
    for (i = 0; i < k; i++) {
        scanf("%d%d", &course, &num_stu);
        for (j = 0; j < num_stu; j++) {
            scanf("%s", name);
            p = hash2(name);
            f[p].push_back(course);
        }
    }
    for (j = 0; j < n; j++) {
        scanf("%s", name);
        p = hash2(name);
        printf("%s %lu", name, f[p].size());
        sort(f[p].begin(), f[p].end());
        for (i = 0; i < f[p].size(); i++) {
            printf(" %d", f[p][i]);
        }
        printf("\n");
    }
    return 0;
}
