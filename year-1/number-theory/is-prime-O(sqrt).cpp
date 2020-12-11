//
// Created by n2k on 22.11.2020.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "NO";
        return 0;
    }

    int i = 2;
    bool isPrime = true;
    while (i * i <= n) {
        if (n % i == 0) {
            isPrime = false;
            break;
        } else
            ++i;
    }

    cout << (isPrime ? "YES" : "NO");
}
