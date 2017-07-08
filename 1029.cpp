#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long int a[1000010], b[1000010];

int main() {
    int n1, n2;
    long int  median;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%ld", &a[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%ld", &b[i]);
    }

    int i = 0, j = 0;
    for (int k = 0; k <= (n1+n2-1)/2; k++) {
        if (i < n1 && j < n2) {
            median = a[i] < b[j] ? a[i++] : b[j++];
        } else if (i < n1) {
            median = a[i++];
        } else if (j < n2) {
            median = b[j++];
        }
    }
    printf("%ld\n", median);
    return 0;
}
