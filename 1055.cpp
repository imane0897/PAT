#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct people {
    char name[10];
    int age;
    int worth;
    bool operator< (const people& rhs) const {
        if (worth != rhs.worth) {
            return worth > rhs.worth;
        } else if (age != rhs.age) {
            return age < rhs.age;
        } else {
            return strcmp(name, rhs.name) < 0;
        }
    }
} ;

int main() {
    int N, K, M, Amin, Amax;
    vector<people> v;
    scanf("%d%d", &N, &K);
    while (N--) {
        people temp;
        scanf("%s%d%d", temp.name, &temp.age, &temp.worth);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= K; i++) {
        scanf("%d%d%d", &M, &Amin, &Amax);
        int count = 0;
        printf("Case #%d:\n", i);
        for (size_t j = 0; j < v.size() && count < M; j++) {
            if (Amin <= v[j].age && v[j].age <= Amax) {
                printf("%s %d %d\n", v[j].name, v[j].age, v[j].worth);
                count++;
            }
        }
        if (count == 0)  printf("None\n");
    }
    return 0;
}
