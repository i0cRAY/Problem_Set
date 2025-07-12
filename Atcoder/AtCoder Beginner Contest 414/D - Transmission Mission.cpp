#include <bits/stdc++.h>

#define int long long

int N, M;
std::vector<int> a;
std::vector<int> gap;

int32_t main() {
    std::cin >> N >> M;

    a.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 1; i <= N - 1; i++) {
        int g = a[i + 1] - a[i];
        gap.emplace_back(g);
    }

    std::sort(gap.begin(), gap.end(), std::greater<int>());

    int cost = a[N] - a[1];

    for (int i = 0; i < M - 1; i++) {
        cost -= gap[i];
    }

    std::cout << cost << std::endl;
    return 0;
}
