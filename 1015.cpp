#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

bool is_prime(int a) {
    if (a < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

string to_radix(int a, int d) {
    string s;
    while (a > 0) {
        s = s + to_string(a % d);
        a = a / d;
    }
    return s;
}

int to_decimal(string s, int d) {
    int k = 0;
    for (auto c : s) {
        k = k * d + c - '0';
    }
    return k;
}

int main(void) {
    int n, d;
    while (scanf("%d", &n) && n > 0) {
        scanf("%d", &d);

        if (is_prime(n)) {
            string a = to_radix(n, d);
            if (is_prime(to_decimal(a, d))) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        } else {
            printf("No\n");
        }

    }
    return 0;
}
