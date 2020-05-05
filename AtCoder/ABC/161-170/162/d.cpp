#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

int n;
string s;

ll search(vector<int> &a, vector<int> &b, vector<int> &c) {
    ll cnt = 0;
    for (auto tb : b) {
        // ll ta = upper_bound(all(a), tb) - a.begin();
        ll tc = c.end() - upper_bound(all(c), tb);
        for (int i = 0, size = a.size(); i < size; ++i) {
            if (a[i] > tb)
                break;
            if (binary_search(all(c), tb + (tb - a[i])))
                cnt += max(0LL, tc - 1);
            else
                cnt += tc;
        }
    }
    return cnt;
}

int main() {
    vector<int> r, g, b;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R')
            r.push_back(i);
        else if (s[i] == 'G')
            g.push_back(i);
        else if (s[i] == 'B')
            b.push_back(i);
    }

    ll sum = 0;
    sum += search(r, g, b);
    sum += search(r, b, g);
    sum += search(g, r, b);
    sum += search(g, b, r);
    sum += search(b, r, g);
    sum += search(b, g, r);
    cout << sum << endl;

    return 0;
}