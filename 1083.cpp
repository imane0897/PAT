#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct student {
    string name;
    string id;
    int grade;
} ;

bool cmp (const student a, const student b) {
    return a.grade > b.grade;
}

int main(void) {
    int n, grade1, grade2;
    vector<student> a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        student temp;
        cin >> temp.name >> temp.id >> temp.grade;
        a.push_back(temp);
    }
    scanf("%d%d", &grade1, &grade2);

    int m = n;
    for (int i = 0; i < m; i++) {
        if (a[i].grade < grade1 || a[i].grade > grade2) {
            a.erase(a.begin() + i);
            m--;
            i--;
        }
    }

    if (a.empty()) {
        printf("NONE\n");
    } else {
        sort(a.begin(), a.end(), cmp);
        for(auto x : a) {
            cout << x.name << ' ' << x.id << endl;
        }
    }
    return 0;
}
