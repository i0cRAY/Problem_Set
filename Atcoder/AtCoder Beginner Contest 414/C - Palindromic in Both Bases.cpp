#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

#define int long long

bool is_palindrome_in_base(int n, int base) {
    if (n <= 0) return false;
    std::vector<int> digits;
    int temp = n;
    while (temp > 0) {
        digits.push_back(temp % base);
        temp /= base;
    }
    
    int left = 0;
    int right = digits.size() - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A;
    int N;
    std::cin >> A >> N;

    int total_sum = 0;

    for (int k = 1; ; ++k) {
        
        int p_even = k;
        int temp = k;
        while (temp > 0) {
            if (__builtin_mul_overflow(p_even, 10, &p_even)) {
                p_even = N + 1;
                break;
            }
            p_even += temp % 10;
            temp /= 10;
        }
        
        int p_odd = k;
        temp = k / 10; 
        while (temp > 0) {
            if (__builtin_mul_overflow(p_odd, 10, &p_odd)) {
                p_odd = N + 1;
                break;
            }
            p_odd += temp % 10;
            temp /= 10;
        }

        // 兩個都超過 N 就可以結束了
        if (p_odd > N && p_even > N) {
            break;
        }
        
        if (p_odd <= N) {
            if (is_palindrome_in_base(p_odd, A)) {
                total_sum += p_odd;
            }
        }
        
        if (p_even <= N) {

            if (is_palindrome_in_base(p_even, A)) {
                total_sum += p_even;
            }
        }
    }

    std::cout << total_sum << std::endl;

    return 0;
}
