#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct people {
    int id;
    int virtue;
    int talent;
    int all;
    int tag;
    bool operator<(const people& rhs) const{
        if (tag != rhs.tag) {
            return tag < rhs.tag;
        } else if (all != rhs.all) {
            return all > rhs.all;
        } else if (virtue != rhs.virtue) {
            return virtue > rhs.virtue;
        } else {
            return id < rhs.id;
        }
    }
} ;

int main() {
    int N, L, H;
    vector<people> v;
    scanf("%d%d%d", &N, &L, &H);
    while (N--) {
        people temp;
        scanf("%d%d%d", &temp.id, &temp.virtue, &temp.talent);
        if (temp.virtue >= L && temp.talent >= L) {
            temp.all = temp.virtue + temp.talent;
            if (temp.virtue >= H && temp.talent >= H) {
                temp.tag = 1;
            } else if (temp.virtue >= H && temp.talent < H) {
                temp.tag = 2;
            } else if (temp.virtue >= temp.talent) {
                temp.tag = 3;
            } else {
                temp.tag = 4;
            }
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end());
    printf("%lu\n", v.size());
    for (auto it : v) {
        printf("%d %d %d\n", it.id, it.virtue, it.talent);
    }
    return 0;
}
