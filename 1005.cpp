#include <iostream>
#include <stdio.h>

std::string trans(int a) {
    std::string s;
    switch (a) {
        case 0: s = "zero";break;
        case 1: s = "one";break;
        case 2: s = "two";break;
        case 3: s = "three";break;
        case 4: s = "four";break;
        case 5: s = "five";break;
        case 6: s = "six";break;
        case 7: s = "seven";break;
        case 8: s = "eight";break;
        case 9: s = "nine";
    }
    return s;
}

int main(void) {
    char a;
    int i, sum;
    std::string s;

    sum = 0;
    while (scanf("%c", &a) != EOF) {
        if (int(a) >= 48) {
            sum += int(a) - 48;
        }
    }

    if (sum == 0) {
        s = "zero";
    } else {
        s = "";
        while (sum > 0) {
            i = sum % 10;
            sum = sum / 10;
            if (s.size() > 0) {
                s = trans(i) + " " + s;
            } else {
                s = trans(i);
            }
        }
    }
    std::cout << s << '\n';
    return 0;
}
