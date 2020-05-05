#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, m;
    pair<int, int> p[200], q[1000];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }
    sort(q, q + m);
    int x = p[0].first, y = p[0].second;
    for (int i = 0; i < m; ++i) {
        int dx = q[i].first - x;
        int dy = q[i].second - y;
        bool f = true;
        for (int j = 0; j < n; ++j) {
            if (binary_search(q, q + m, make_pair(p[j].first + dx, p[j].second + dy)) == false) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << dx << " " << dy << endl;
            break;
        }
    }

    return 0;
}