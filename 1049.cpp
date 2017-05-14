#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
    int count = 0;
    int i, j;
    string a;
    cin >> a;

    for (i = 0; i < a.size(); i++) {
        a[i] = a[i] - '0';
    }
    int n = a.size() - 1;

    // first number
    if (n >= 1) {
        if (a[0] > 1)   count += pow(10, n);
        else if (a[0] == 1) {
            for (j = 1; j <= n; j++) {
                count += pow(10, n-j) * a[j];
            }
            count += 1;
        }
    }

    // last number
    for (j = 0; j < n; j++) {
        count += pow(10, n-j-1) * a[j];
    }
    if (a[n] > 0)    count += 1;

    // middle numbers (optional)
    for (i = 1; i < n; i++) {
        j = 0;
        for (; j < i - 1; j++) {
            count += pow(10, n-j-1) * a[j];
        }
        if (a[i] > 1) {
            count += pow(10, n-j-1) * (a[j] + 1);
        } else if (a[i] == 1) {
            count += pow(10, n-j-1) * a[j] + 1;
            j += 2;
            for (; j <= n; j++) {
                count += pow(10, n-j) * a[j];
            }
        } else {
            count += pow(10, n-j-1) * a[j];
        }
    }
    cout << count << endl;
    
    return 0;
}
