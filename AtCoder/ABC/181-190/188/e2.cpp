#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n);
    vector<P> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = make_tuple(a[i], i);
    }
    sort(s.begin(), s.end());
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    queue<int> que;
    vector<int> visit(n, 0);
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        int sv = get<1>(s[i]);
        if (visit[sv])
            continue;
        que.push(sv);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            visit[u] = 1;
            for (auto v : g[u]) {
                chmax(ans, a[v] - a[sv]);
                if (!visit[v]) {
                    que.push(v);
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}