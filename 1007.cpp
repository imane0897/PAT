#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct add_sum {
    int result;
    int lhs;
    int rhs;
} ;

int num[10010];

int main() {
    int K;
    add_sum cur_sum = {0, 0, 0}, max_sum = {-1, 0, 0};
    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        scanf("%d", &num[i]);
        cur_sum.result += num[i];
        cur_sum.rhs = i;

        if (max_sum.result < cur_sum.result) {
            max_sum = cur_sum;
        }
        if (cur_sum.result < 0) {
            cur_sum.result = 0;
            cur_sum.lhs = i + 1;
        }
    }

    if (max_sum.result == -1) {
        printf("%d %d %d\n", 0, num[0], num[K-1]);
    } else {
        printf("%d %d %d\n", max_sum.result, num[max_sum.lhs], num[max_sum.rhs]);
    }
    return 0;
}
