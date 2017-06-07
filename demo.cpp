#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool queue_empty (vector<int> v[], int size) {
    for (int i = 0; i < size; i++) {
        if (!v[i].empty()) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n = 10;
    for (int p = 1; p <= 10; p++) {
        printf("%d ", (p + 1 + n -1) % n + 1);
    }
    printf("\n");
    for (int p = 1; p <= 10; p++) {
        printf("%d ", (p + 1 + n) % n);
    }
    printf("\n");
    return 0;
}
