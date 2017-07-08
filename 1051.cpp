#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

bool check_legal_sequence(const int& m, const int& n, const int pop[]) {
    int stack_max = 0;
    vector <int> stack;

    stack.push_back(0);
    for (int p = 0; p < n; p++) {
        if (stack.back() < pop[p]) {
            if (m - (int)stack.size() + 1 < pop[p] - stack_max) {
                return false;
            }
            for (int i = stack_max + 1; i < pop[p]; i++) {
                stack.push_back(i);
            }
            stack_max = pop[p];
        } else if (stack.back() == pop[p]) {
            stack.pop_back();
        } else if (stack.back() > pop[p]) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n, k, pop[1010];
    scanf("%d %d %d", &m, &n, &k);

    while (k--) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &pop[i]);
        }
        if (check_legal_sequence(m, n, pop)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
