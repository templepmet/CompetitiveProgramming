#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int a[100000];

int main() {
    int n;
    ll v = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v += a[i] * (i % 2 ? -1 : 1);
    }
    cout << v << " ";
    for (int i = 0; i < n - 1; ++i) {
        v = (v - a[i]) * (-1) + a[i];
        cout << v << " ";
    }
    cout << endl;

    return 0;
}