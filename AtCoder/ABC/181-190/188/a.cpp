#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int x, y;
    cin >> x >> y;
    cout << (abs(x - y) < 3 ? "Yes" : "No") << endl;

    return 0;
}