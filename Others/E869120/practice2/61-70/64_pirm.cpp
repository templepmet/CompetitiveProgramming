#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

using T = tuple<int, int>;

vector<T> ad[100000];

int main() {
    int v, e, s, t, w;
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        cin >> s >> t >> w;
        ad[s].emplace_back(w, t);
        ad[t].emplace_back(w, s);
    }

    priority_queue<T, vector<T>, greater<T>> q;
    vector<int> used(v, 0);
    q.emplace(0, 0);
    int ans = 0;
    while (!q.empty()) {
        auto [w, t] = q.top();
        q.pop();
        if (used[t])
            continue;
        used[t] = 1;
        ans += w;
        for (auto tup : ad[t]) {
            q.push(tup);
        }
    }
    cout << ans << endl;

    return 0;
}