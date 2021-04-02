#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int co[2000][2000];

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    fill(co[0], co[n], INF);
    vector<vector<int>> ad(n), re(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        a--; b--;
        chmin(co[a][b], c);
        ad[a].push_back(b);
        re[b].push_back(a);
    }
    for (int k = 0; k < n; ++k) {
        for (auto i : re[k]) {
            for (auto j : ad[k]) {
                if (chmin(co[i][j], co[i][k] + co[k][j])) {
                    ad[i].push_back(j);
                    re[j].push_back(i);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << (co[i][i] == INF ? -1 : co[i][i]) << endl;
    }

    return 0;
}