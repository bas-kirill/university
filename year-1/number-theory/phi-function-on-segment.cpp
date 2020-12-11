//
// Created by n2k on 22.11.2020.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

uint64_t slow_phi(uint64_t n) {
    if (n == 1)
        return 1;
    uint64_t ans = 0;
    for (uint64_t i = 1; i <= n - 1; ++i) {
        if (gcd(i, n) == 1)
            ++ans;
    }
    return ans;
}

uint64_t phi(uint64_t n) {
    uint64_t phi = n;
    uint64_t d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            while (n % d == 0)
                n /= d;
            phi = phi - phi / d;
        } else {
            ++d;
        }
    }

    if (n > 1)
        phi -= phi / n; // Last number - prime number
    return phi;
}

int main() {
    uint64_t a, b;
    cin >> a >> b;

    uint64_t ans = 0;
    for (uint64_t i = a; i <= b; ++i) {
        ans += phi(i);
    }

    cout << ans;
    return 0;
}
