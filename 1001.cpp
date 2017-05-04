#include <iostream>
#include <stdio.h>

using namespace std;

int main(void) {
    int a, b, c;
    std::string d;
    int count, flag, i;
    while(scanf("%d %d", &a, &b) != EOF) {
        c = a + b;

        count = 0;
        flag = 0;
        i = 0;
        d = "";

        if (c == 0) {
            std::cout << 0 << '\n';
            continue;
        }

        if (c < 0) {
            flag = 1;
            c = -c;
        }

        while (c > 0) {
            i = c % 10;
            d = std::to_string(i) + d;          // convert int to string
            c = c / 10;
            count += 1;
            if (count == 3 && c > 0) {
                d = "," + d;
                count = 0;
            }
        }

        if (flag == 1) {
            d = "-" + d;
        }

        std::cout << d << '\n';
    }
    return 0;
}
