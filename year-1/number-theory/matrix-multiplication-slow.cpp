
//
// Created by n2k on 23.11.2020.
//

#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 100;

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

void input(int A[][MAXN], int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
}

void output(int A[][MAXN], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << A[i][j] << ' ';
        cout << endl;
    }
}


int main() {
//    ifstream cin("input.txt");
    int p, q, r;
    cin >> p >> q >> r;
    input(a, p, q);
    input(b, q, r);
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            int sum = 0;
            for (int k = 0; k < q; ++k) {
                sum += a[i][k] * b[k][j];
            }

            c[i][j] = sum;
        }
    }

    output(c, p, r);
}