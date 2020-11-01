#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

set<int> use, add, tmp;

int main() {
    int n, m, a[100], w[10];
    while (cin >> n >> m && n > 0) {
        use.clear();
        add.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> w[i];
        }

        use.insert(0);
        for (int i = 0; i < m; ++i) {
            tmp = use;
            for (int t : tmp) {
                use.insert(abs(t - w[i]));
                use.insert(t + w[i]);
            }
        }

        bool isadd = false;
        for (int i = 0; i < n; ++i) {
            if (use.find(a[i]) == use.end()) {
                tmp.clear();
                auto addend = add.end();
                for (auto t : use) {
                    if (!isadd || add.find(abs(t - a[i])) != addend)
                        tmp.insert(abs(t - a[i]));
                    if (!isadd || isadd && add.find(t + a[i]) != addend)
                        tmp.insert(t + a[i]);
                }
                if (!isadd) {
                    isadd = true;
                    add = tmp;
                    continue;
                }
                for (auto it = add.begin(); it != addend; ++it) {
                    if (tmp.find(*it) == tmp.end()) {
                        add.erase(it);
                    }
                }
                if (add.empty())
                    break;
            }
        }

        if (!isadd) {
            cout << 0 << endl;
            continue;
        }

        if (add.empty())
            cout << -1 << endl;
        else
            cout << *add.begin() << endl;
    }

    return 0;
}