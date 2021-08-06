#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

// 木の直径＋１が答え

int n;
vector<vector<int>> ad;
vector<int> d;

void dfs(int p, int u, int t) {
    d[u] = t;
    for (auto v : ad[u]) {
        if (v != p) {
            dfs(u, v, t + 1);
        }
    }
}

int getDiameter() {
    d.resize(n, 0);
    dfs(-1, 0, 0);
    int st = max_element(d.begin(), d.end()) - d.begin();
    d.resize(n, 0);
    dfs(-1, st, 0);
    int diam = *max_element(d.begin(), d.end());
    return diam;
}

int main() {
    int a, b;
    cin >> n;
    ad.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--; b--;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    cout << getDiameter() + 1 << endl;

    return 0;
}