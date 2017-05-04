#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;

bool palindromic(std::array<int, 100>& a, int length) {
    int i, j = length - 1;
    for (i = 0; i != j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n, b, i, length;
    std::array<int, 100> a;

    // input
    scanf("%d%d", &n, &b);
    //////

    i = 0;
    length = 0;
    while(n >= b) {
        a[i++] = n % b;
        n = n / b;
        length++;
    }
    a[i] = n;
    length++;

    // output
    if (palindromic(a, length)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (i = length - 1; i > 0; i--) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[0]);
    //////

    return 0;
}
