#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

/*
    arg x: compress of x
    ret v: sorted of x
*/
template <class T>
vector<T> compress(vector<T> &x) {
    vector<T> v = x;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0, l = x.size(); i < l; ++i) {
        x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
    }
    return v;
}

int main() {
    int n, c, a, b, d;
    cin >> n >> c;
    vector<int> v(n);
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> d;
        v[i] = d;
        x.push_back(a);
        x.push_back(b + 1);
    }
    vector<int> vals = compress(x);
    int l = *max_element(x.begin(), x.end()) + 2;
    vector<ll> w(l, 0);
    for (int i = 0; i < n; ++i) {
        w[x[i * 2]] += v[i];
        w[x[i * 2 + 1]] -= v[i];
    }
    for (int i = 1; i < l; ++i) {
        w[i] += w[i - 1];
    }
    for (int i = 0; i < l; ++i) {
        chmin(w[i], (ll)c);
    }
    ll ans = 0;
    for (int i = 0; i + 1 < l - 1; ++i) {
        ans += (vals[i + 1] - vals[i]) * w[i];
    }
    cout << ans << endl;

    return 0;
}