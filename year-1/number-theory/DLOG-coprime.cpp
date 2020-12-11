//
// Created by n2k on 23.11.2020.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int64_t mod(int64_t a, int64_t m) {
    return a % m;
}

int64_t binPowmod(int64_t a, int64_t n, int64_t m) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return mod(binPowmod(mod(a*a, m), n / 2, m), m);
    else
        return mod(a * binPowmod(mod(a, m), n - 1, m), m);
}

int64_t binSearch(vector<pair<int64_t, int64_t>>& a, int64_t x) {
    int64_t l = -1;
    int64_t r = a.size();
    while (l + 1 < r) {
        int64_t m = l + (r - l) / 2;

        if (a[m].first == x) {
            r = m;
        } else if (a[m].first < x) {
            l = m;
        } else
            r = m;
    }

    return l + 1;
}

int main() {
//    ifstream cin("input.txt");
    int64_t a, b, m;
    cin >> a >> b >> m;

    int64_t n = ceil(sqrt(m)) + 1;
    vector<pair<int64_t, int64_t>> f1(ceil(m / double(n)));

    for (int64_t p = ceil(m / double(n)); p >= 1; --p) {
        f1[p - 1].first = binPowmod(a, n * p, m);
        f1[p - 1].second = p;
    }

    sort(f1.begin(), f1.end());

    int64_t ans = -1;
    int64_t x;
    for (int64_t q = 0; q <= n; ++q) {
        int64_t f2 = mod(b * binPowmod(a, q, m), m);
        int idx = binSearch(f1, f2);
        if (idx < f1.size() and f1[idx].first == f2) {
            x = n * f1[idx].second - q;
            if (x < m) {
                ans = x;
                break;
            }
        }
    }

    cout << ans;
}