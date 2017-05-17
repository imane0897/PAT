#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2501;
vector<string> course[MAX];

int main(void) {
    int n, k, c, i, j, cour, max_cour = 0;
    string name;

    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        cin >> name;
        scanf("%d", &c);
        for (j = 0; j < c; j++) {
            scanf("%d", &cour);
            max_cour = max_cour > cour ? max_cour : cour;
            course[cour].push_back(name);
        }
    }

    for (i = 1; i <= max_cour; i++) {
        printf("%d %lu\n", i, course[i].size());
        sort(course[i].begin(), course[i].end());
        for (auto c : course[i]) {
            cout << c << '\n';
        }
    }
    return 0;
}
