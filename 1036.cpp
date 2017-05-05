#include <iostream>
#include <stdio.h>
using namespace std;

struct student {
    std::string name;
    std::string gender;
    std::string id;
    int score;
} ;

int main(void) {
    int n;
    student a[1000];
    int low_m_score = 101, low_m_index = -1;
    int high_f_score = -1, high_f_index = -1;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].name >> a[i].gender >> a[i].id >> a[i].score;
        if (a[i].gender == "M") {
            if (low_m_score > a[i].score) {
                low_m_score = a[i].score;
                low_m_index = i;
            }
        } else {
            if (high_f_score < a[i].score) {
                high_f_score = a[i].score;
                high_f_index = i;
            }
        }
    }

    if (low_m_index != -1 && high_f_index != -1) {
        std::cout << a[high_f_index].name << ' ' << a[high_f_index].id << '\n';
        std::cout << a[low_m_index].name << ' ' << a[low_m_index].id << '\n';
        printf("%d\n", high_f_score - low_m_score);
    } else if (low_m_index == -1) {
        std::cout << a[high_f_index].name << ' ' << a[high_f_index].id << '\n';
        std::cout << "Absent" << '\n';
        std::cout << "NA" << '\n';
    } else if (high_f_index == -1) {
        std::cout << "Absent" << '\n';
        std::cout << a[low_m_index].name << ' ' << a[low_m_index].id << '\n';
        std::cout << "NA" << '\n';
    }

    return 0;
}
