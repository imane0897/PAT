#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int id;
    int score[10];
    int total_score;
    int psp;
    bool show;
    node() {
        fill(score, score + 10, -1);
        total_score = 0;
        show = false;
        psp = 0;
    }
    bool operator< (const node& rhs) const {
        if (total_score != rhs.total_score) {
            return total_score > rhs.total_score;
        } else if (show != rhs.show) {
            return show;
        } else if (psp != rhs.psp) {
            return psp > rhs.psp;
        } else {
            return id < rhs.id;
        }
    }
} ;

int main() {
    int N, K, M, problem[10];
    scanf("%d%d%d", &N, &K, &M);
    vector<node> v(N + 1);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &problem[i]);
    }
    while (M--) {
        int tid, index, score;
        scanf("%d%d%d", &tid, &index, &score);
        v[tid].id = tid;
        if (score > -1)  v[tid].show = true;
        if (score > v[tid].score[index]) {
            if (score == problem[index])  v[tid].psp++;
            if (v[tid].score[index] > 0) {
                v[tid].total_score += score - v[tid].score[index];
            } else {
                v[tid].total_score += score;
            }
            v[tid].score[index] = score;
        } else if (score == -1 && v[tid].score[index] == -1) {
            v[tid].score[index] = 0;
        }
    }
    sort(v.begin() + 1, v.end());
    int rank = 1, rank_p = 0;
    for (size_t i = 1; i < v.size(); i++) {
        if (!v[i].show)  break;
        if (i > 0 && v[i].total_score == v[i-1].total_score) {
            printf("%d", rank_p);
        } else {
            printf("%d", rank);
            rank_p = rank;
        }
        printf(" %05d %d", v[i].id, v[i].total_score);
        for (int j = 1; j <= K; j++) {
            if (v[i].score[j] >= 0)  printf(" %d", v[i].score[j]);
            else printf(" -");
        }
        printf("\n");
        rank++;
    }
    return 0;
}
