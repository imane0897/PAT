#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct student {
    int id;
    int c;
    int m;
    int e;
    int a;
    int rc;
    int rm;
    int re;
    int ra;
} ;

bool cmpc(const student a, const student b) {
    return a.c > b.c;
}

bool cmpm(const student a, const student b) {
    return a.m > b.m;
}

bool cmpe(const student a, const student b) {
    return a.e > b.e;
}

bool cmpa(const student a, const student b) {
    return a.a > b.a;
}

int main(void) {
    int m, n, k;
    vector<student> a;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        student temp;
        scanf("%d%d%d%d", &temp.id, &temp.c, &temp.m, &temp.e);
        temp.a = (temp.c + temp.m + temp.e) / 3;
        temp.ra = 0; temp.rc = 0; temp.rm = 0; temp.re = 0;
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), cmpc);
    k = 1;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].rc == 0)    a[i].rc = k++;
        if (i < a.size() - 1 && a[i].c == a[i+1].c) {
            a[i+1].rc = a[i].rc;
            k++;
        }
    }

    sort(a.begin(), a.end(), cmpm);
    k = 1;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].rm == 0)    a[i].rm = k++;
        if (i < a.size() - 1 && a[i].m == a[i+1].m) {
            a[i+1].rm = a[i].rm;
            k++;
        }
    }

    sort(a.begin(), a.end(), cmpe);
    k = 1;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].re == 0)    a[i].re = k++;
        if (i < a.size() - 1 && a[i].e == a[i+1].e) {
            a[i+1].re = a[i].re;
            k++;
        }
    }

    sort(a.begin(), a.end(), cmpa);
    k = 1;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].ra == 0)    a[i].ra = k++;
        if (i < a.size() - 1 && a[i].a == a[i+1].a) {
            a[i+1].ra = a[i].ra;
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        int query_id;
        bool flag = true;

        scanf("%d", &query_id);
        for (auto x : a) {
            if (x.id == query_id) {
                if (x.ra <= x.rc && x.ra <= x.rm && x.ra <= x.re) {
                    printf("%d A\n", x.ra);
                } else if (x.rc <= x.ra && x.rc <= x.rm && x.rc <= x.re) {
                    printf("%d C\n", x.rc);
                } else if (x.rm <= x.ra && x.rm <= x.rc && x.rm <= x.re) {
                    printf("%d M\n", x.rm);
                } else {
                    printf("%d E\n", x.re);
                }
                flag = false;
                break;
            }
        }
        if (flag)    printf("N/A\n");
    }
    return 0;
}
