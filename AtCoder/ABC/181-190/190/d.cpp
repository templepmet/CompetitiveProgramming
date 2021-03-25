#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

/*
    約数全列挙 O(sqrt(n))
*/
vector<ll> divider(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

ll N;

int check(ll n) {
    ll m = N / n;
    ll a2 = m - (n - 1);
    if (a2 % 2 == 0)
        return 1;
    return 0;
}

int main() {
    cin >> N;
    N *= 2;
    auto d = divider(N);
    int cnt = 0;
    for (auto v : d) {
        cnt += check(v);
    }
    cout << cnt << endl;

    return 0;
}