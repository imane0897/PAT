#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int n, i, j;
    char c;
    std::string s = "";

    while (scanf("%c", &c) != EOF) {
        s += c;
    }

    n = 1;
    for (j = 0; j < s.size(); j++) {
        i = 1;
        while (j - i >= 0 && j + i < s.size() && s[j-i] == s[j+i]) {
            i++;
        }
        i = i * 2 - 1;
        n = n > i ? n : i;
    }

    for (j = 0; j < s.size(); j++) {
        i = 0;
        while (j - i >= 0 && j + i + 1< s.size() && s[j-i] == s[j+i+1]) {
            i++;
        }
        i = 2 * i;
        n = n > i ? n : i;
    }
    std::cout << n << '\n';

    return 0;
}
