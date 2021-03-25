#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, s, d, x, y;
    bool f = false;
    cin >> n >> s >> d;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x < s && y > d) {
            f = true;
        }
    }

    cout << (f ? "Yes" : "No") << endl;

    return 0;
}