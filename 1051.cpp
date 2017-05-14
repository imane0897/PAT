#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    int m, n, k;
    int a[1010], i;
    bool flag;

    scanf("%d%d%d", &m, &n, &k);
    while (k--) {
        flag = true;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (i = 0; i < n - m; i++) {
            if (a[i] > m + i) {
                flag = false;
                break;
            } else if (a[i] > m) {

            }
        }
        if (flag) {
            int b[1010] = {0};
            for (i = 0; i < n; i++) {
                b[a[i]] = 1;
                int index = a[i + 1];
                if (index < n && b[index+1] == 0) {
                    for (int j = index + 2; j <= n; j++) {
                        if (b[j]) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (!flag)    break;
            }
        }

        if (flag)   printf("YES\n");
        else        printf("NO\n");
    }
    return 0;
}
