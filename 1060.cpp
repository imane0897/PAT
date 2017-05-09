#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int n;
    std::string a, b;
    std::string a_coe, b_coe;
    int a_exp, b_exp;

    std::cin >> n >> a >> b;

    if (a[0] != '0') {
        a_coe = "";
        int i;
        for (i = 0; a_coe.size() < n && i < a.size(); i++) {
            if (a[i] != '.') {
                a_coe += a[i];
            }
        }
        a_exp = 0;
        while (a_exp < a.size() && a[a_exp] != '.') {
            a_exp++;
        }
    } else if (a == "0") {
        a_coe = "0";
        a_exp = 0;
    } else {
        a_coe = "";
        int i;
        for (i = 0; i < a.size(); i++) {
            if (a[i] != '0' && a[i] != '.') {
                break;
            }
        }
        if (i == a.size()) {
            a_exp = 0;
        } else {
            for (; a_coe.size() < n && i < a.size(); i++) {
                a_coe += a[i];
            }
        }

        a_exp = 0;
        for (i = 0; i < a.size(); i++) {
            if (a[i] == '.') {
                break;
            }
        }
        for (; i < a.size(); i++) {
            if (a[i] == '0') {
                a_exp--;
            } else {
                break;
            }
        }
    }


    if (b[0] != '0') {
        b_coe = "";
        for (int i = 0; b_coe.size() < n && i < b.size(); i++) {
            if (b[i] != '.') {
                b_coe += b[i];
            }
        }

        b_exp = 0;
        while (b_exp < b.size() && b[b_exp] != '.') {
            b_exp++;
        }
    } else if (b == "0") {
        b_exp = 0;
    } else {
        b_coe = "";
        b_exp = 0;
        int i;
        for (i = 2; i < b.size(); i++) {
            if (b[i] == '0') {
                b_exp--;
            } else {
                break;
            }
        }
        if (i == b.size()) {
            b_exp = 0;
        } else {
            for (; b_coe.size() < n && i < b.size(); i++) {
                b_coe += b[i];
            }
        }
    }


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
