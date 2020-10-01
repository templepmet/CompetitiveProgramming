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

int v, e, r;
vector<int> to[100000];
vector<int> cost[100000];

int dist[100000];

int main() {
    int s, t, d;
    cin >> v >> e >> r;
    rep(i, e) {
        cin >> s >> t >> d;
        to[s].push_back(t);
        cost[s].push_back(d);
    }
    fill(dist, dist + v, INF);
    dist[r] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, r);
    while (!q.empty()) {
        pii u = q.top();
        q.pop();
        if (u.first > dist[u.second])
            continue;
        for (int i = 0, k = to[u.second].size(); i < k; ++i) {
            if (dist[to[u.second][i]] > u.first + cost[u.second][i]) {
                dist[to[u.second][i]] = u.first + cost[u.second][i];
                q.emplace(u.first + cost[u.second][i], to[u.second][i]);
            }
        }
    }
    rep(i, v) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}