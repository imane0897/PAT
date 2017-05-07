#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    char a[10010], b[10010];
    int a_length = 0, b_length = 0;

    while (scanf("%c", &a[a_length]) != EOF && a[a_length] != '\n') {
        a_length++;
    }

    while(scanf("%c", &b[b_length]) != EOF && b[b_length] != '\n') {
        b_length++;
    }

    int i, j;
    int flag = 0;
    for (i = 0; i < a_length; i++) {
        for (j = 0; j < b_length; j++) {
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            flag = 0;
        } else {
            printf("%c", a[i]);
        }
    }
    printf("\n");


    return 0;
}
