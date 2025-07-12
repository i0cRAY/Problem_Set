#include <bits/stdc++.h>

int N, L, R, X, Y;

int main() {
    std::cin >> N >> L >> R;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> X >> Y;
        if (X <= L && R <= Y) cnt++;
    }

    std::cout << cnt << std::endl;
    return 0;
}
