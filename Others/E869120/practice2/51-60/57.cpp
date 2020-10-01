#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
vector<int> to[100], cost[100];

int dijkstra(int a, int b) {
    int d[100];
    fill(d, d + n, INF);
    d[a] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, a);
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int u = t.second;
        int c = t.first;
        if (d[u] < c)
            continue;
        for (int i = 0, k = to[u].size(); i < k; ++i) {
            if (d[to[u][i]] > c + cost[u][i]) {
                d[to[u][i]] = c + cost[u][i];
                q.emplace(d[to[u][i]], to[u][i]);
            }
        }
    }
    return (d[b] == INF ? -1 : d[b]);
}

int main() {
    int k, m, a, b, c, d, e;
    cin >> n >> k;
    while (k--) {
        cin >> m;
        if (m) {
            cin >> c >> d >> e;
            c--; d--;
            to[c].push_back(d);
            to[d].push_back(c);
            cost[c].push_back(e);
            cost[d].push_back(e);
        }
        else {
            cin >> a >> b;
            cout << dijkstra(a - 1, b - 1) << endl;
        }
    }

    return 0;
}