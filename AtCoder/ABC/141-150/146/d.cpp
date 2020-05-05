#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

vector<int> t[100000];
pair<int, int> e[100000];
map<pair<int, int>, int> color;
int maxc = 0;

void dfs(int u, int v, int c) {
    if (c > 0) {
        maxc = max(maxc, c);
        color[make_pair(min(u, v), max(u, v))] = c;
    }
    int cc = 1;
    for (auto w : t[u]) {
        if (w == v)
            continue;
        if (cc == c)
            cc++;
        dfs(w, u, cc++);
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--; b--;
        e[i] = make_pair(min(a, b), max(a, b));
        t[a].push_back(b);
        t[b].push_back(a);
    }
    dfs(0, 0, 0);
    cout << maxc << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << color[e[i]] << endl;
    }

    return 0;
}