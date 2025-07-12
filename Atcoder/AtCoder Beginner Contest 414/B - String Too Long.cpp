#include <bits/stdc++.h>

int N, l;
char c;

int main() {
    std::cin >> N;

    int len = 0;

    std::string s;

    while (N--) {
        std::cin >> c >> l;
        len += l;
        if (len > 100) {
            std::cout << "Too Long" << std::endl;
            return 0;
        }
        else {
            for (int i = 0; i < l; i++) {
                s += c;
            }
        }
    }

    std::cout << s << std::endl;
    return 0;
}
