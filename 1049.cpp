#include <iostream>
#include <stdio.h>
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
    int n, count, i, j;
    string s(3, 0);
    cin >> n;

    int count2 = 0, a = 0, b = 0, c = 0;
    // for (j = 1; j < 1000; j++) {
    //     count = 0;
    //     for (i = 0; i <= n; i++) {
    //         count += count_one(i);
    //     }
        j = 0;
        for (a = 0; a < 10; a++) {
            for (b = 0; b < 10; b++) {
                for (c = 0; c< 10; c++) {
                    count2 = 0;
                    if (a > 1)    count2 += 100;
                    else if (a == 1)   count2 += 10 * b + c + 1;
                    if (b > 1)    count2 += 10 * (a + 1);
                    else if (b == 1)   count2 += 10 * a + c + 1;
                    else    count2 += a * 10;
                    if (c != 0)    count2 += 10 * a + b + 1;
                    else    count2 += 10 * a + b;

                    count = 0;
                    for (i = 0; i <= j; i++) {
                        count += count_one(i);
                    }
                    if (count != count2) {
                        printf("%d %d %d\n", j, count, count2);
                    }
                    j++;
                }
            }
        }

    // }
    printf("done.\n");
    return 0;
}
