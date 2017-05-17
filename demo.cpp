#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

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
    int a;
    cin >> a;
    cout << is_prime(a) << endl;
    return 0;
}
