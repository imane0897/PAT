#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 1010;

struct account {
    std::string id;
    std::string password;
} ;

int main(void) {
    int modify[MAXN], n;
    account a[MAXN];
    scanf("%d", &n);

    for (int i = 0; i < MAXN; i++) {
        modify[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].id;
        std::cin >> a[i].password;

        for (size_t j = 0; j < a[i].password.size(); j++) {
            if (a[i].password[j] == '1') {
                a[i].password[j] = '@';
                modify[i] = 1;
            } else if (a[i].password[j] == '0') {
                a[i].password[j] = '%';
                modify[i] = 1;
            } else if (a[i].password[j] == 'l') {
                a[i].password[j] = 'L';
                modify[i] = 1;
            } else if (a[i].password[j] == 'O') {
                a[i].password[j] = 'o';
                modify[i] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < MAXN; i++) {
        if (modify[i]) {
            count++;
        }
    }
    if (count == 0 && n == 1) {
        printf("There is %d account and no account is modified\n", n);
        return 0;
    } else if (count == 0) {
        printf("There are %d accounts and no account is modified\n", n);
        return 0;
    }
    printf("%d\n", count);
    for (int i = 0; i < MAXN; i++) {
        if (modify[i]) {
            std::cout << a[i].id << ' ' << a[i].password << '\n';
        }
    }
    return 0;
}
