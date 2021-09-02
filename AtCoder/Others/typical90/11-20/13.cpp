#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

vector<vector<P>> ad;

// single shortest path length
vector<int> sspl(int s) {
    int n = ad.size();
    vector<int> cost(n, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    cost[s] = 0;
    while (!que.empty()) {
        auto [co, u] = que.top();
        que.pop();
        if (co > cost[u]) continue;
        for (auto [v, c] : ad[u]) {
            if (cost[v] > cost[u] + c) {
                cost[v] = cost[u] + c;
                que.emplace(cost[v], v);
            }
        }
    }
    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    ad.resize(n);
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        a--; b--;
        ad[a].emplace_back(b, c);
        ad[b].emplace_back(a, c);
    }
    auto start = sspl(0);
    auto goal = sspl(n - 1);
    for (int i = 0; i < n; ++i) {
        cout << start[i] + goal[i] << endl;
    }

    return 0;
}

// 始点と終点からSPするだけ