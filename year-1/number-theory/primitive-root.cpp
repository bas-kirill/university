
//
// Created by n2k on 23.11.2020.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

uint64_t n, p;

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

uint64_t mod(uint64_t a, uint64_t m) {
    return a % m;
}

uint64_t binPowmod(uint64_t a, uint64_t n, uint64_t m) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return mod(binPowmod(mod(a*a, m), n / 2, m), m);
    else
        return mod(a * binPowmod(mod(a, m), n - 1, m), m);
}

uint64_t getPhi(uint64_t n) {
    uint64_t phi = n;
    uint64_t i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            phi -= phi / i;
        } else {
            ++i;
        }
    }

    if (n > 1)
        phi -= phi / n;
    return phi;
}

// O(n) = O(sqrt(n)) * O(sqrt(n))
bool isPrimitiveRootNaive(uint64_t g, uint64_t m) {
    if (gcd(g, m) != 1)
        return -1;


    uint64_t phi = getPhi(m); // O(sqrt(n))

    uint64_t ans = -1;
    for (uint64_t k = 1; k <= phi; ++k) { // O(sqrt(n))
        if (binPowmod(g, k, m) == 1) {
            ans = k;
            break;
        }
    }

    return (ans == phi);
}

bool isPrimitiveRootDivisors(uint64_t g, uint64_t m) {
    if (gcd(g, m) != 1) {
        return false;
    }

    uint64_t phi = getPhi(m);

    vector<uint64_t> factors;
    int d = 2;
    for (uint64_t i = 1; i <= phi; ++i) {
        if (phi % i == 0)
            factors.push_back(i);
    }

    uint64_t ans = -1;
    for (uint64_t factor : factors) {
        if (binPowmod(g, factor, m) == 1) {
            ans = factor;
            break;
        }
    }

    return (ans == phi);
}

bool isPrimitiveRootFast(uint64_t g, uint64_t m) {
    if (gcd(g, m) != 1) {
        return false;
    }

    uint64_t phi = getPhi(m);
    vector<uint64_t> prime;
    int p = 2;
    while (p * p <= phi) {
        if (phi % p == 0) {
            while (phi % p == 0)
                phi /= p;
            prime.push_back(p);
        } else {
            ++p;
        }
    }

    if (phi > 1)
        prime.push_back(phi);

    phi = getPhi(m);
    int ans = phi;
    for (int i = 0; i < prime.size(); ++i) {
        if (binPowmod(g, phi / prime[i], m) == 1) {
            ans = phi / prime[i];
            break;
        }
    }
    return (ans == phi);
}

int main() {
//    ifstream cin("input.txt");
    cin >> n >> p;
    vector<uint64_t> q(n);

    for (uint64_t i = 0; i < n; ++i) {
        cin >> q[i];

        cout << (isPrimitiveRootFast(q[i], p) ? "YES" : "NO") << endl;
    }
}