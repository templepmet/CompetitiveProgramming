#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    ll y[61][2] = {};
    y[0][0] = 1;
    y[0][1] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == "AND") {
            y[i + 1][0] += y[i][0] * 2 + y[i][1];
            y[i + 1][1] += y[i][1];
        }
        else { // OR
            y[i + 1][1] += y[i][1] * 2 + y[i][0];
            y[i + 1][0] += y[i][0];
        }
    }
    cout << y[n][1] << endl;

    return 0;
}