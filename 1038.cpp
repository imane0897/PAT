#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

string num[10010];

bool cmp(const string& a, const string& b) {
    return a + b <= b + a;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num+n, cmp);

    int i = 0;
    for (i = 0; i < n; i++) {
        int a = stoi(num[i], nullptr, 10);
        if (a != 0) {
            printf("%d", a);
            i++;
            break;
        }
    }
    if (i < n) {
        for (; i < n; i++) {
            cout << num[i];
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
