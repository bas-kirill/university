//
// Created by n2k on 22.11.2020.
//

#include <iostream>
#include <cmath>
using namespace std;

int extGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }

    int _x, _y;
    int d = ext_gcd(b, a % b, _x,_y);
    x = _y, y = _x - a / b * _y;
    return d;
}

int main() {
    int n, p;
    cin >> n >> p;

    if (n == 1) {
        cout << -1;
        return 0;
    }

    int x, y;
    int d = extGcd(p, n, x, y);

    if (d != 1) {
        cout << -1;
        return 0;
    }

    x = (x + n) % n;
    cout << x;
}