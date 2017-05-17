#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct num {
    int p;
    int k;
} ;

vector<num> a;

bool is_prime(int a) {
    if (a == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    long long int n;
    num t;

    scanf("%lld", &n);

    if (n == 1 || n == 2 || n == 3) {
        printf("%lld=%lld\n", n, n);
        return 0;
    }

    printf("%lld=", n);
    for (int i = 2; i <= sqrt(n); i++) {
        if (!is_prime(i)) {
            continue;
        }
        if (n % i == 0) {
            t.p = i; t.k = 1;
            a.push_back(t);
            n = n / i;
        }
        while (n % i == 0) {
            a[a.size()-1].k++;
            n = n / i;
        }
        if (is_prime(n)) {
            t.p = n; t.k = 1;
            a.push_back(t);
        }
    }

    int i;
    for (i = 0; i < a.size() - 1; i++) {
        if (a[i].k > 1) {
            printf("%d^%d*", a[i].p, a[i].k);
        } else {
            printf("%d*", a[i].p);
        }
    }
    if (a[i].k > 1) {
        printf("%d^%d\n", a[i].p, a[i].k);
    } else {
        printf("%d\n", a[i].p);
    }

    return 0;
}
