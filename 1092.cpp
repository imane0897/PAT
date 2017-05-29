#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void) {
    int h1[125] = {0}, h2[125] = {0};
    char a[1010], b[1010];
    scanf("%s", a);
    scanf("%s", b);

    for (size_t i = 0; i < strlen(a); i++) {
        h1[(int)a[i]]++;
    }
    for (size_t i = 0; i < strlen(b); i++) {
        h2[(int)b[i]]++;
    }

    bool result = true;
    int count = 0;
    for (int i = 48; i < 123; i++) {
        if (h2[i] > h1[i]) {
            result = false;
            count += h2[i] - h1[i];
        }
    }

    if (result) {
        printf("Yes %lu\n", strlen(a)-strlen(b));
    } else {
        printf("No %d\n", count);
    }
    return 0;
}
