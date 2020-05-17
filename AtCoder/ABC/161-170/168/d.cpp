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

vector<int> g[100000];
int ans[100000], d[100000];

// void dfs(int u, int v, int dd) {
//     if (d[v] <= dd)
//         return;
//     d[v] = dd;
//     ans[v] = u;
//     for (auto t : g[v]) {
//         dfs(v, t, dd + 1);
//     }
// }

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(d, d + n, INF);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto t = q.top();
        int u = t.second;
        int dd = t.first;
        q.pop();

        for (auto v : g[u]) {
            if (d[v] > dd + 1) {
                d[v] = dd + 1;
                ans[v] = u;
                q.push(make_pair(dd + 1, v));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] == INF) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; ++i) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}