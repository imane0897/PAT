#include <iostream>
#include <stdio.h>
using namespace std;

string s;

void string_add() {
    int flag = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        s[i] = s[i] + s[i] + flag - '0';
        if (s[i] > '9') {
            flag = 1;
            s[i] -= 10;
        } else {
            flag = 0;
        }
    }
    if (flag) {
        s = '1' + s;
    }
}

int main(void) {
    string hash1(10, 0);
    string hash2(10, 0);

    cin >> s;
    for (auto c : s) {
        hash1[c-'0']++;
    }
    string_add();
    for (auto c : s) {
        hash2[c-'0']++;
    }
    if (hash1 == hash2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    cout << s << endl;
    return 0;
}
