#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
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

    vector<int> v[5];
    v[1].push_back(2);
    for(int i = 0; i < 5; i++) {
        if (!v[i].empty()) {
            cout << v[i].front() << endl;
        }
    }
    return 0;
}
