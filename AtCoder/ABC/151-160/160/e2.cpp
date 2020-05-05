#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

ll x, y, a, b, c;
ll p[100001], q[100001], r[100001];

int main() {
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; ++i)
        cin >> p[i];
    for (int i = 0; i < b; ++i)
        cin >> q[i];
    for (int i = 0; i < c; ++i)
        cin >> r[i];
    p[a] = 0;
    q[b] = 0;
    r[c] = 0;
    sort(p, p + a + 1);
    sort(q, q + b + 1);
    sort(r, r + c + 1);
    ll ans = 0, xy = 0, xx = 0, yy = 0;
    while (xy < x + y) {
        if (p[a] >= q[b] && p[a] >= r[c]) {
            if (xx < x) {
                ans += p[a];
                xy++;
                xx++;
            }
            a--;
        }
        else if (q[b] >= p[a] && q[b] >= r[c]) {
            if (yy < y) {
                ans += q[b];
                xy++;
                yy++;
            }
            b--;
        }
        else if (r[c] >= p[a] && r[c] >= q[b]) {
            ans += r[c];
            c--;
            xy++;
        }
    }
    cout << ans << endl;

    return 0;
}