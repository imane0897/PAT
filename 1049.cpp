#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;


int count_one(int n) {
    int count = 0;
    int i;
    while(n > 0) {
        i = n % 10;
        if (i == 1) {
            count++;
        }
        n = n / 10;
    }
    return count;
}


int main(void) {
    long long int count = 0;
    int i, j;
    string a;

    // while (cin >> a) {
    char y, x, b, c, d;
    int index = 0;

    // for (y = '0'; y <= '9'; y++)
    for (x = '0'; x <= '9'; x++)
    for (b = '0'; b <= '9'; b++)
    for (c = '0'; c <= '9'; c++)
    for (d = '0'; d <= '9'; d++) {
        a = string(1, x) + string(1, b) + string(1, c) + string(1, d);
        count = 0;


        while(a[0] == '0') {
            a = a.substr(1);
        }

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
        // cout << "cout first num " << count << endl;

        // last number
        for (j = 0; j < n; j++) {
            count += pow(10, n-j-1) * a[j];
        }
        if (a[n] > 0)    count += 1;
        // cout << "cout last num " << count << endl;

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
        // cout << count << endl;


        int count2 = 0;
	    for (int i = 0; i <= index; i++) {
	        count2 += count_one(i);
	    }
        if (count2 != count) {
            printf("%d %d %lld\n", index, count2, count);
        }
        index++;

    }
    printf("done\n");
    return 0;
}
