#include <iostream>
#include <stdio.h>
using namespace std;


int main(void) {
    std::string s;
    int n1, n2, n3;
    int i, j;
    char U[100][100];

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            U[i][j] = ' ';
        }
    }

    std::cin >> s;

    n1 = n2 = (s.size() + 2) / 3;
    n3 = s.size() + 2 - n1 - n2;

    int index = 0;
    for (i = 0; i < n1; i++) {
        U[i][0] = s[index];
        index += 1;
    }
    for (i = 1; i < n2; i++) {
        U[n2-1][i] = s[index];
        index += 1;
    }
    for (i = n3 - 2; i >= 0; i--) {
        U[i][n2] = s[index];
        index += 1;
    }

    for (i = 0; i < n1; i++) {
        for (j = 0; j <= n2; j++) {
            printf("%c", U[i][j]);
        }
        printf("\n");
    }
    return 0;
}
