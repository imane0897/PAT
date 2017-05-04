#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;

int main(void) {
    int k, index, count;
    float value;
    std::array<float, 1005> a;

    for (size_t i = 0; i < a.size(); i++) {
        a[i] = 0;
    }

    for (int ii = 0; ii < 2; ii ++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d%f", &index, &value);
            a[index] += value;
        }
    }

    count = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            count ++;
        }
    }

    if (count == 0) {
        printf("0\n");
    } else {
        std::cout << count;
        for (int i = a.size()-1; i >= 0; i--) {
            if (a[i] != 0) {
                printf(" %d %.1f", i, a[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
