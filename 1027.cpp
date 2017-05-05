#include <iostream>
#include <stdio.h>
using namespace std;

char trans(int n) {
    if (n < 10) {
        return n + 48;
    } else {
        switch (n) {
            case 10: return 'A';
            case 11: return 'B';
            case 12: return 'C';
        }
    }
    return ' ';
}

int main(void) {
    char color[6] = {'0'};
    int r, g, b;

    scanf("%d%d%d", &r, &g, &b);

    color[0] = trans(r / 13);
    color[1] = trans(r % 13);
    color[2] = trans(g / 13);
    color[3] = trans(g % 13);
    color[4] = trans(b / 13);
    color[5] = trans(b % 13);

    printf("#");
    for (int i = 0; i < 6; i++) {
        printf("%c", color[i]);
    }
    printf("\n");

    return 0;
}
