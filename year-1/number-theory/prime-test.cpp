
//
// Created by n2k on 23.11.2020.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

bool isPrime(int a) {
    int b = 2;
    while (b * b <= a) {
        if (a % b == 0)
            return false;
        else
            ++b;
    }

    return true;
}

bool fermaPrimeTest(int64_t n) {
    return (binPowmod(int64_t(2), n - 1, n) == 1);
}


int main() {
//    ifstream cin("input.txt");
    int64_t n;
    cin >> n;
    cout << fermaPrimeTest(n);
}