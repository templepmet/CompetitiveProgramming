#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int n;
vector<int> ad[1000000];
int d[1000000];
int c[1000000];

int dfs(int u) {
    if (c[u] == 2) // visited
        return d[u];
    if (c[u] == 1) { // now path
        return -1;
    }
    c[u] = 1;
    for (auto v : ad[u]) {
        int t = dfs(v);
        if (t == -1) return -1;
        chmax(d[u], t + 1);
    }
    c[u] = 2;
    return d[u];
}

int conv(int i, int j) {
    int a = min(i, j);
    int b = max(i, j);
    return a * n + b;
}

int main() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a; a--;
        for (int j = 0; j < n - 2; ++j) {
            cin >> b; b--;
            ad[conv(i, a)].push_back(conv(i, b));
            a = b;
        }
    }

    int ans = 0;
    for (int i = 0; i < n * n; ++i) {
        int t = dfs(i);
        if (t == -1) {
            cout << t << endl;
            return 0;
        }
        chmax(ans, t);
    }
    cout << ans + 1 << endl;

    return 0;
}