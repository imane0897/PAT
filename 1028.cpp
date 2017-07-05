#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int id;
    string name;
    int score;
} ;

bool cmp1(const student a, const student b) {
    return a.id < b.id;
}

bool cmp2(const student a, const student b) {
    if (a.name == b.name) {
        return a.id < b.id;
    } else {
        return a.name < b.name;
    }
}

bool cmp3(const student a, const student b) {
    if (a.score == b.score) {
        return a.id < b.id;
    } else {
        return a.score < b.score;
    }
}

int main() {
    int n, c;
    vector<student> stu;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        student a;
        scanf("%d", &a.id);
        cin >> a.name;
        scanf("%d", &a.score);
        stu.push_back(a);
    }

    switch (c) {
        case 1: sort(stu.begin(), stu.end(), cmp1); break;
        case 2: sort(stu.begin(), stu.end(), cmp2); break;
        case 3: sort(stu.begin(), stu.end(), cmp3); break;
    }

    for (auto it:stu) {
        printf("%06d ", it.id);
        cout << it.name;
        printf(" %d\n", it.score);
    }
    return 0;
}
