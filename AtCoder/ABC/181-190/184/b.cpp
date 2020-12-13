#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    for (auto c : s) {
        if (c == 'x') {
            x = max(x - 1, 0);
        }
        else {
            x++;
        }
    }
    cout << x << endl;

    return 0;
}