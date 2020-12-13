#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int d[100];

int hanoi(int n) {
    if (d[n] > 0) {
        return d[n];
    }
    int t = 2 * hanoi(n - 1) + n;
    return d[n] = t;
}

int calc(int n) {
    return pow(2, n + 1) - n - 2;
}

int main() {
    int n =10;
    d[1] = 1;
    hanoi(n);
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " " << calc(i) << endl;
    }

    return 0;
}