#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char cards[54][2];
int shuff[54];

void init_cards() {
    int j = 0;
    for (int i = 1; i <= 13; i++) {
        cards[j][0] = 'S';
        cards[j][1] = i;
        j++;
    }
    for (int i = 1; i <= 13; i++) {
        cards[j][0] = 'H';
        cards[j][1] = i;
        j++;
    }
    for (int i = 1; i <= 13; i++) {
        cards[j][0] = 'C';
        cards[j][1] = i;
        j++;
    }
    for (int i = 1; i <= 13; i++) {
        cards[j][0] = 'D';
        cards[j][1] = i;
        j++;
    }
    for (int i = 1; i <= 2; i++) {
        cards[j][0] = 'J';
        cards[j][1] = i;
        j++;
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    init_cards();
    for (int i = 0; i < 54; i++) {
        scanf("%d", &shuff[i]);
    }
    while(n--) {
        char cards_copy[54][2];
        for(int i = 0; i < 54; i++) {
            cards_copy[shuff[i] - 1][0] = cards[i][0];
            cards_copy[shuff[i] - 1][1] = cards[i][1];
        }
        memcpy(cards, cards_copy, sizeof(cards));
    }
    for (int i = 0; i < 53; i++) {
        printf("%c%d ", cards[i][0], cards[i][1]);
    }
    printf("%c%d\n", cards[53][0], cards[53][1]);
    return 0;
}
