#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {
    int h2[100] = {0};
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);

    int t = 0;
    for (size_t i = 0; i < strlen(b); i++) {
        t = (int)b[i];
        if (t > 96)    t -= 32;
        h2[t]++;
    }

    for (size_t i = 0; i < strlen(a); i++) {
        t = (int)a[i];
        if (t > 96)    t -= 32;
        if (h2[t] == 0) {
            printf("%c", t);
            h2[t] = 1;
        }
    }
    putchar('\n');
    return 0;
}
