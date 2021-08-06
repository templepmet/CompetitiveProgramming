#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, q;
    ll b;
    cin >> n;
    vector<ll> a(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = -1e18;
    a[n + 1] = 1e18;
    sort(a.begin(), a.end());
    cin >> q;
    while (q--) {
        cin >> b;
        auto it = upper_bound(a.begin(), a.end(), b);
        cout << min(*it - b, b - *(it - 1)) << endl;
    }

    return 0;
}