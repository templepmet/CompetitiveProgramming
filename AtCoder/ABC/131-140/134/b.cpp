#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n, d;
    cin >> n >> d;
    int m = 2 * d + 1;
    cout << (n + m - 1) / m << endl;

    return 0;
}