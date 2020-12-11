//
// Created by n2k on 22.11.2020.
//

#include <iostream>
using namespace std;

int ext_gcd(int a, int b, int &x, int &y) {
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
    int a, b;
    cin >> a >> b;

    int x, y;
    int d = ext_gcd(a, b, x, y);

    if (d != 1) {
        cout << 0 << " " << 0;
        return 0;
    }

    cout << x << ' ' << y;
}