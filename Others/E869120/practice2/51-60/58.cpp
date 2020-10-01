#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pli = pair<ll, int>;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

vector<int> ad[100000];
int z[100000], s;
ll d[100000];

void dfs(int u, int c) {
    if (z[u] <= c || c > s)
        return;
    z[u] = c;
    for (auto v : ad[u]) {
        dfs(v, c + 1);
    }
}

int main() {
    int n, m, k, p, q, a, b;
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    vector<int> zc(k);
    rep(i, k) {
        cin >> zc[i];
    } 
    rep(i, m) {
        cin >> a >> b;
        --a; --b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    fill(z, z + n, INF);
    for (auto c : zc) {
        dfs(c - 1, 0);
    }
    z[0] = INF;
    z[n - 1] = INF;

    fill(d, d + n, 1e18);
    d[0] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.emplace(0, 0);
    while (!que.empty()) {
        pli top = que.top();
        que.pop();
        int u = top.second;
        ll c = top.first;
        if (d[u] < c)
            continue;
        for (auto v : ad[u]) {
            if (z[v] == 0) continue;
            ll cz = (z[v] < INF ? q : p);
            if (d[v] > c + cz) {
                d[v] = c + cz;
                que.emplace(d[v], v);
            }
        }
    }
    cout << d[n - 1] - p << endl;

    return 0;
}