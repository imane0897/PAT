#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int k, cur = 0, next, sum = 0;

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &next);
        if (next > cur) {
            sum += 6 * (next - cur);
        } else if (next < cur) {
            sum += 4 * (cur - next);
        }
        sum += 5;
        cur = next;
    }
    printf("%d\n", sum);
    return 0;
}
