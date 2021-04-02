#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int co[2000][2000];

void dijkstra(vector<vector<P>> &ad, int s) {
    co[s][s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while (!que.empty()) {
        auto [cur, u] = que.top();
        que.pop();
        if (cur > co[s][u]) continue;
        for (auto [v, c] : ad[u]) {
            if (co[s][v] > cur + c) {
                co[s][v] = cur + c;
                que.emplace(co[s][v], v);
            }
        }
    }
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    fill(co[0], co[n], INF);
    vector<vector<P>> ad(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        a--; b--;
        ad[a].emplace_back(b, c);
    }

    for (int i = 0; i < n; ++i) {
        dijkstra(ad, i);
    }

    for (int i = 0; i < n; ++i) {
        int d = INF;
        for (auto [a, c] : ad[i]) {
            if (i == a) {
                chmin(d, c);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            chmin(d, co[i][j] + co[j][i]);
        }
        cout << (d == INF ? -1 : d) << endl;
    }

    return 0;
}