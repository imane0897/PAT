#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

struct book {
    string id;
    string title;
    string author;
    string keywords[6];
    string publisher;
    string year;
} ;

int main(void) {
    int n, m, i, j, x;
    int count;
    char c;
    string search;
    string results[10010];
    book lib[10010];

    cin >> n;
    getchar();
    for (i = 0; i < n; i++) {
        getline(cin, lib[i].id);
        getline(cin, lib[i].title);
        getline(cin, lib[i].author);
        int k = 0;
        while (cin>>lib[i].keywords[k]) {
            k++;
            c = getchar();
            if (c == '\n')    break;
        }
        getline(cin, lib[i].publisher);
        getline(cin, lib[i].year);
    }

    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        scanf("%d", &x);
        getline(cin, search);
        cout << x << search << endl;
        search = search.substr(2);
        count = 0;

        switch (x) {
            case 1:
                for (i = 0; i < n; i++) {
                    if (lib[i].title == search) {
                        results[count] = lib[i].id;
                        count++;
                    }
                }
                break;
            case 2:
                for (i = 0; i < n; i++) {
                    if (lib[i].author == search) {
                        results[count] = lib[i].id;
                        count++;
                    }
                }
                break;
            case 3:
                for (i = 0; i < n; i++) {
                    for (int k = 0; k < 6; k++) {
                        if (lib[i].keywords[k] == search) {
                            results[count] = lib[i].id;
                            count++;
                            break;
                        }
                    }
                }
                break;
            case 4:
                for (i = 0; i < n; i++) {
                    if (lib[i].publisher == search) {
                        results[count] = lib[i].id;
                        count++;
                    }
                }
                break;
            case 5:
                for (i = 0; i < n; i++) {
                    if (lib[i].year == search) {
                        results[count] = lib[i].id;
                        count++;
                    }
                }
                break;
        }
        sort(results, results + count);
        for (int it = 0; it < count; it++) {
            std::cout << results[it] << endl;
        }
        if (count == 0) {
            std::cout << "Not Found" << endl;
        }
    }
    return 0;
}
