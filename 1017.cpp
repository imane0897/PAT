#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct customer {
    int arrive_time;
    int process_time;
} ;

bool cmp (const customer a, const customer b){
    return a.arrive_time < b.arrive_time;
}

int main(void) {
    int num_windows, num_customer, hh, mm, ss, proc;
    vector<customer> a;
    customer temp;

    scanf("%d%d", &num_customer, &num_windows);
    for (int i = 0; i < num_customer; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &proc);
        if (hh < 17) {
            if (proc > 60)  proc = 60;
            temp.arrive_time = hh * 60 * 60 + mm * 60 + ss;
            temp.process_time = proc * 60;
            a.push_back(temp);
        }
    }

    sort(a.begin(), a.end(), cmp);

    int result = 0;
    vector<int> v(num_windows, 8 * 60 * 60);
    for (auto k : a) {
        int earliest_ind = 0;
        for (size_t i = 0; i < v.size(); i++) {
            if (v[i] < v[earliest_ind])    earliest_ind = i;
        }
        if (v[earliest_ind] <= k.arrive_time) {
            v[earliest_ind] = k.arrive_time + k.process_time;
        } else {
            result += v[earliest_ind] - k.arrive_time;
            v[earliest_ind] += k.process_time;
        }
    }
    if (a.size() == 0)     printf("size = 0\n");
    else    printf("%.1f\n", result / 60.0 / a.size());
    return 0;
}
