#include <bits/stdc++.h>

using namespace std;

#define INF ((ll)1e17)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

ll d[100][100];
int v, e;

int wf() {
    rep(k, v) {
        rep(i, v) {
            rep(j, v) {
                if (d[i][k] == INF || d[k][j] == INF)
                    continue;
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
            if (d[i][i] < 0)
                return 1;
        }
    }
    return 0;
}

int main() {
    int s, t, di;
    cin >> v >> e;
    fill(d[0], d[v], INF);
    rep(i, v) d[i][i] = 0;
    rep(i, e) {
        cin >> s >> t >> di;
        d[s][t] = di;
    }
    if (wf()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, v) {
        rep(j, v) {
            if (d[i][j] == INF)
                cout << "INF";
            else
                cout << d[i][j];
            if (j < v - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}