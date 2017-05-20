#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int END_TIME = 540;
const int MAX_QUE = 25;
const int MAX = 0xffff;

queue <int> windows[MAX_QUE];
int a[1010], b[1010];

int main(void){
    int n, m, num_people, num_query;

    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));

    scanf("%d%d%d%d", &n, &m, &num_people, &num_query);
    for (int i = 0; i < num_people; i++) {
        scanf("%d", &a[i]);
    }

    int t_count = 0, p_count = 0, k = 0, latest_time = END_TIME;
    while (t_count < latest_time) {

        while (p_count < m * n && k < num_people && t_count < END_TIME) {
            int min_ind = -1, min = m;
            for (int i = 0; i < n; i++) {
                if (windows[i].size() < min) {
                    min_ind = i;
                    min = windows[i].size();
                }
            }
            windows[min_ind].push(k++);
            p_count++;
        }

        int min_t = MAX;
        for (int i = 0; i < n; i++) {
            if (!windows[i].empty() && a[windows[i].front()] < min_t) {
                min_t = a[windows[i].front()];
            }
        }
        t_count += min_t;
        for (int i = 0; i < n; i++) {
            if (!windows[i].empty()) {
                a[windows[i].front()] -= min_t;
                if (a[windows[i].front()] == 0) {
                    b[windows[i].front()] = t_count;
                    windows[i].pop();
                    p_count--;
                }
                if (t_count < END_TIME && t_count + a[windows[i].front()] > latest_time) {
                    latest_time = t_count + a[windows[i].front()];
                }
            }
        }
    }
    // printf("latest_time = %d\n", latest_time);
    // output
    int index;
    for (int i = 0; i < num_query; i++) {
        scanf("%d", &index);
        index -= 1;
        if (b[index] > -1) {
            printf("%02d:%02d\n", 8 + b[index] / 60, b[index] % 60);
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}
