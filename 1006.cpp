#include <iostream>
#include <stdio.h>
using namespace std;

struct sign{
    std::string id;
    int in_hh;
    int in_mm;
    int in_ss;
    int out_hh;
    int out_mm;
    int out_ss;
} ;

sign sign_in, sign_out, a;

void refresh_sign_in() {
    sign_in.id = a.id;
    sign_in.in_hh = a.in_hh;
    sign_in.in_mm = a.in_mm;
    sign_in.in_ss = a.in_ss;
}

void refresh_sign_out() {
    sign_out.id = a.id;
    sign_out.out_hh = a.out_hh;
    sign_out.out_mm = a.out_mm;
    sign_out.out_ss = a.out_ss;
}

int main(void) {
    int m;

    sign_in.id = ""; sign_in.in_hh = 24; sign_in.in_mm = 60; sign_in.in_ss = 60;
    sign_out.id = ""; sign_out.out_hh = 0; sign_out.out_mm = 0; sign_out.out_ss = 0;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        std::cin >> a.id;
        scanf("%d", &a.in_hh);
        getchar();
        scanf("%d", &a.in_mm);
        getchar();
        scanf("%d", &a.in_ss);
        scanf("%d", &a.out_hh);
        getchar();
        scanf("%d", &a.out_mm);
        getchar();
        scanf("%d", &a.out_ss);

        // if a comes earlier than cur sign_in
        if (a.in_hh < sign_in.in_hh) {
            refresh_sign_in();
        } else if (a.in_hh == sign_in.in_hh) {
            if (a.in_mm < sign_in.in_mm) {
                refresh_sign_in();
            } else if (a.in_mm == sign_in.in_mm) {
                if (a.in_ss < sign_in.in_ss) {
                    refresh_sign_in();
                }
            }
        }

        // if a goes later than cur sign_out
        if (a.out_hh > sign_out.out_hh) {
            refresh_sign_out();
        } else if (a.out_hh == sign_out.out_hh) {
            if (a.out_mm < sign_out.out_mm) {
                refresh_sign_out();
            } else if (a.out_mm == sign_out.out_mm) {
                if (a.out_ss < sign_out.out_ss) {
                    refresh_sign_out();
                }
            }
        }

    }

    std::cout << sign_in.id << ' ' << sign_out.id << '\n';
    return 0;
}
