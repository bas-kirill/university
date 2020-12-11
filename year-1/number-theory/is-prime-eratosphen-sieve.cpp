//
// Created by n2k on 22.11.2020.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int64_t n) {
    bool isPrime = true;
    int64_t i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            isPrime = false;
            break;
        } else
            ++i;
    }

    return isPrime;
}

int main() {
    int64_t n;
    cin >> n;

    if (n == 1) {
        cout << "NO";
        return 0;
    }

    size_t sieveSize = 25'000'000 + 1; // 40, 80, 120, 240
    vector<char> prime(sieveSize, true);
    prime[1] = false;
    for (int64_t i = 4; i <= sieveSize; i += 2)
        prime[i] = false;

    for (int64_t i = 2; i <= sieveSize; ++i) {
        if (i % 2 == 0)
            continue;
        if (prime[i]) {
            for (int64_t j = i; j <= sieveSize; j += i) {
                if (j == i)
                    continue;
                prime[j] = false;
            }
        }
    }

    for (int64_t i = 2; i <= sieveSize and i < n; ++i) {
        if (prime[i] and n % i == 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
