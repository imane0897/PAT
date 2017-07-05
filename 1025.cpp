#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct student {
    string id;
    int score;
    int place;
    int local_rank;
    int rank;
    bool operator < (const student& rhs) const {
        if (score == rhs.score) return id < rhs.id;
        else return score > rhs.score;
    }
} ;

int main () {
    int k, n;
    vector<student> stu;

    scanf("%d\n", &k);
    for (int j = 1; j <= k; j++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            student a;
            cin >> a.id;
            scanf("%d", &a.score);
            a.place = j;
            stu.push_back(a);
        }
        sort(stu.end()-n, stu.end());
        stu[stu.size() - n].local_rank = 1;
        for (size_t i = stu.size() - n + 1; i < stu.size(); i++) {
            if (stu[i].score == stu[i-1].score) {
                stu[i].local_rank = stu[i-1].local_rank;
            } else {
                stu[i].local_rank = i - (stu.size() - n) + 1;
            }
        }
    }

    sort (stu.begin(), stu.end());
    stu[0].rank = 1;
    for (size_t i = 1; i < stu.size(); i++) {
        if (stu[i].score == stu[i-1].score) {
            stu[i].rank = stu[i-1].rank;
        } else {
            stu[i].rank = i + 1;
        }
    }

    printf("%lu\n", stu.size());
    for (auto it:stu) {
        cout << it.id;
        printf(" %d %d %d\n", it.rank, it.place, it.local_rank);
    }
    return 0;
}
