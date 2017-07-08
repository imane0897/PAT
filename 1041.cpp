#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int hash_array[10010] = {0};
int a[100010];

int main() {
    int n, x, ptr = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (hash_array[x] == 0)  a[ptr++] = x;
        hash_array[x]++;
    }
    for (int i = 0; i < ptr; i++) {
        if (hash_array[a[i]] == 1) {
            printf("%d\n", a[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
