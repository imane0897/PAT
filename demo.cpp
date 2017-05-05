#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int a[10][10] = {0};
    for (int i = 0; i < 10; i++) {
        a[0][i] = 1;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
