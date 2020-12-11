//
// Created by n2k on 22.11.2020.
//

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

bool isPrime(uint64_t n) {
    uint64_t d = 2;
    while (d * d <= n) {
        if (n % d == 0) {
            return false;
        } else
            ++d;
    }

    return true;
}

int main() {
    ofstream cout("output.txt");
    int MAXN = 100'000'000;
    for (int i = 2; i <= MAXN; ++i) {
        if (isPrime(i))
            cout << i << ", ";
    }
}
