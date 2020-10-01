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

int n, k;
int r[5000], c[5000], d[5000][5000];
vector<int> ad[5000];

void dijk(int a) {
    fill(d[a], d[a] + n, INF);
    d[a][a] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, a);
    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        int u = top.second;
        int co = top.first;
        if (co > d[a][u])
            continue;
        for (auto v : ad[u]) {
            if (d[a][v] > co + 1) {
                d[a][v] = co + 1;
                q.emplace(d[a][v], v);
            }
        }
    }
}

int main() {
    int a, b;
    cin >> n >> k;
    rep(i, n) {
        cin >> c[i] >> r[i];
    }
    rep(i, k) {
        cin >> a >> b;
        a--; b--;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    rep(i, n) {
        dijk(i);
    }

    int ship[5000];
    fill(ship, ship + n, INF);
    ship[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        int u = top.second;
        int co = top.first;
        if (co > ship[u])
            continue;
        for (int v = 0; v < n; ++v) {
            if (ship[v] > co + c[u] && d[u][v] <= r[u]) {
                ship[v] = co + c[u];
                q.emplace(ship[v], v);
            }
        }

    }
    cout << ship[n - 1] << endl;

    return 0;
}