#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
    std::string s = "";
    s[0] = 'h';
    std::cout << s << '\n';
    std::cout << "s.size = " << s.size() << '\n';
    return 0;
}
