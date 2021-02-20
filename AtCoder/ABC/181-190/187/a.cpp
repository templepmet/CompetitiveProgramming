#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    string a, b;
    cin >> a >> b;
    int c = 0, d = 0;
    for (int i = 0; i < 3; ++i) {
        c += a[i] - '0';
        d += b[i] - '0';
    }
    cout << max(c, d) << endl;

    return 0;
}