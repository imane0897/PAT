#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int n, i, p;
    std::string a, b;
    std::string a_coe, b_coe;
    int a_exp, b_exp;

    std::cin >> n >> a >> b;

    // part a
    p = a.size();
    for (int j = 0; j < a.size(); j++) {
        if (a[j] == '.')    p = j;
    }
    for (i = 0; i < a.size(); i++) {
        if (a[i] != '0' && a[i] != '.')    break;
    }
    if (i == a.size()) {
        a_coe = "";
        a_exp = 0;
    } else {
        a_coe = "";
        a_exp = 0;
        if (p > i) {
            a_exp = p - i;
        } else if (p == i) {
            a_exp = 0;
        } else {
            a_exp = p - i + 1;
        }
        for (; i < a.size() && a_coe.size() < n; i++) {
            if (a[i] != '.')    a_coe += a[i];
        }
    }
    //////

    // part b
    p = b.size();
    for (i = 0; i < b.size(); i++) {
        if (b[i] == '.')    p = i;
    }
    for (i = 0; i < b.size(); i++) {
        if (b[i] != '0' && b[i] != '.')    break;
    }
    if (i == b.size()) {
        b_coe = "";
        b_exp = 0;
    } else {
        if (p > i) {
            b_exp = p - i;
        } else if (p == i) {
            b_exp = 0;
        } else {
            b_exp = p - i + 1;
        }
        for (; i < b.size() && b_coe.size() < n; i++) {
            if (b[i] != '.')    b_coe += b[i];
        }
    }
    //////

    // std::cout << "a_coe = " << a_coe << ",a_coe.size = " << a_coe.size() << '\n';
    while (a_coe.size() < n) {
        a_coe += "0";
    }
    while (b_coe.size() < n) {
        b_coe += "0";
    }

    if (a_coe == b_coe && a_exp == b_exp) {
        printf("YES ");
        std::cout << "0." << a_coe << "*10^" << a_exp << '\n';
    } else {
        printf("NO ");
        std::cout << "0." << a_coe << "*10^" << a_exp << ' ';
        std::cout << "0." << b_coe << "*10^" << b_exp << '\n';
    }

    return 0;
}
