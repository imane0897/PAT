#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

string s;

void string_add (string t) {
    int flag = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        s[i] = s[i] + t[i] + flag - '0';
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
    int k;
    std::cin >> s >> k;

    for (int i = 0; i < k; i++) {

        string t = s;
        std::reverse(t.begin(), t.end());
        if (s == t) {
            std::cout << s << '\n' << i << '\n';
            return 0;
        } else {
            string_add(t);
        }
    }
    std::cout << s << '\n' << k << '\n';
    return 0;
}
