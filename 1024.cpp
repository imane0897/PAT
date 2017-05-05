#include <iostream>
#include <stdio.h>
using namespace std;


const int MAXN = 1000;
int a[MAXN];
int a_end;


bool palindromic() {
    int i, j = a_end;
    for (i = 0; i != j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}


void reverse_add() {
    int b[MAXN], c[MAXN];

    int j = 0;
    for (int i = a_end; i >= 0; i--) {
        b[j++] = a[i];
    }

    int flag = 0, temp;
    for (int i = a_end; i >= 0; i--) {
        temp = a[i] + b[i] + flag;
        if (temp > 9) {
            flag = 1;
            temp = temp % 10;
        } else {
            flag = 0;
        }
        c[i] = temp;
    }

    if (flag) {
        for (int i = a_end; i >= 0; i--) {
            c[i + 1] = c[i];
        }
        c[0] = flag;
    }

    for (int i = 0; i <= a_end + flag; i++) {
        a[i] = c[i];
    }
    a_end += flag;
}


int main(void) {
    long long int n;
    int k, step;

    scanf("%lld%d", &n, &k);

    a_end = -1;
    while (n > 0) {
        a[++a_end] = n % 10;
        n = n / 10;
    }

    step = 0;
    for (step = 0; step < k; step++) {
        if (palindromic()) {
            break;
        } else {
            reverse_add();
        }
    }

    // output
    if (k == 0) {
        for (int i = a_end; i >= 0; i--){
            printf("%d", a[i]);
        }
    } else {
        for (int i = 0; i <= a_end; i++) {
            printf("%d", a[i]);
        }
    }
    printf("\n%d\n", step);

    return 0;
}
