#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 0xfffff;

struct window {
    int cur_time;
    vector<int> v;
    window() {
        this->cur_time = 0;
    }
} ;

int main() {
    int N, M, K, Q, cus_begin[1010], cus_end[1010] = {0};
    window windows[20];
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for (int i = 0; i < K; i++) {
        scanf("%d", &cus_begin[i]);
    }

    int ptr = 0;
    for (int i = 0; i < N*M && i < K; i++) {
        windows[i%N].v.push_back(ptr++);
    }
    while (true) {
        int shortest = MAX, index = -1;
        for (int i = 0; i < N; i++) {
            if (windows[i].cur_time < 540 && !windows[i].v.empty() &&
            (windows[i].cur_time + cus_begin[windows[i].v.front()] < shortest)) {
                shortest = windows[i].cur_time + cus_begin[windows[i].v.front()];
                index = i;
            }
        }

        if (index >= 0) {
            windows[index].cur_time += cus_begin[windows[index].v.front()];
            cus_end[windows[index].v.front()] = windows[index].cur_time;
            windows[index].v.erase(windows[index].v.begin());
            if (ptr < K)  windows[index].v.push_back(ptr++);
        } else {
            break;
        }
    }

    int q;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q);
        q -= 1;
        if (cus_end[q] > 0) {
            printf("%02d:%02d\n", cus_end[q] / 60 + 8, cus_end[q] % 60);
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}
