#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct customer {
    string name;
    int mo, dd, hh, mm;
    bool state;
    bool operator <(const customer& rhs) const{
        if (name != rhs.name) {
            return name < rhs.name;
        } else if (mo != rhs.mo) {
            return mo < rhs.mo;
        } else if (dd != rhs.dd) {
            return dd < rhs.dd;
        } else if (hh != rhs.hh) {
            return hh < rhs.hh;
        } else {
            return mm < rhs.mm;
        }
    }
} ;

int toll[24];

int minus_time(const customer& a, const customer& b) {
    int sum = 0;
    sum += a.mm - b.mm;
    sum += 60 * (a.hh - b.hh);
    sum += 24 * 60 * (a.dd - b.dd);
    return sum;
}

int add_money(customer a, customer b, int time_m) {
    int money = 0, circle_toll = 0;
    for (int j = 0; j < 24; j++) {
        circle_toll += toll[j] * 60;
    }
    money = circle_toll * (time_m / (24 * 60));
    if (a.hh != b.hh) {
        money += (60 - a.mm) * toll[a.hh];
        if (a.hh == 23)  a.hh = -1;
        for (int i = a.hh+1; i != b.hh; i++) {
            money += 60 * toll[i];
            if (i == 23)  i = -1;
        }
        money += b.mm * toll[b.hh];
    } else {
        if (a.mm > b.mm) {
            money += circle_toll - (a.mm - b.mm) * toll[a.hh];
        } else {
            money += (b.mm - a.mm) * toll[a.hh];
        }
    }
    return money;
}

int main() {
    int n;
    vector<customer> v;

    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        customer a;
        cin >> a.name;
        scanf("%d:%d:%d:%d", &a.mo, &a.dd, &a.hh, &a.mm);
        string s;
        cin >> s;
        if (s == "on-line") a.state = true;
        else a.state = false;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    while (!v.empty()) {
        customer c = v.front(), start, stop;
        int total_amount = 0;
        vector<customer> cus;
        bool flag = true;

        while (!v.empty() && v.front().name == c.name) {
            if (v.front().state == flag) {
                cus.push_back(v.front());
                flag = !flag;
            } else if (v.front().state && !flag) {
                if (!cus.empty()) cus.pop_back();
                cus.push_back(v.front());
            }
            v.erase(v.begin());
        }
        cout << c.name;
        printf(" %02d\n", c.mo);
        int sz = cus.size();
        sz = sz & 1 ? sz - 1 : sz;
        for (int i = 0; i < sz; i+=2) {
            start  = cus[i];
            stop = cus[i+1];
            printf("%02d:%02d:%02d ", start.dd, start.hh, start.mm);
            printf("%02d:%02d:%02d ", stop.dd, stop.hh, stop.mm);
            int time_m = minus_time(stop, start);
            printf("%d ", time_m);
            int m = add_money(start, stop, time_m);
            printf("$%d.%02d\n", m/100, m%100);
            total_amount += m;
        }
        printf("Total amount: $%d.%02d\n", total_amount/100, total_amount%100);
    }
    return 0;
}
