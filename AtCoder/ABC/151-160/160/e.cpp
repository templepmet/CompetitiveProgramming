#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

ll x, y, a, b, c;
ll p[100000], q[100000], r[100000];

int main() {
    priority_queue<ll> que;
    cin >> x >> y >> a >> b >> c;
    for (int i = 0; i < a; ++i)
        cin >> p[i];
    for (int i = 0; i < b; ++i)
        cin >> q[i];
    for (int i = 0; i < c; ++i) {
        cin >> r[i];
        que.push(r[i]);
    }
    sort(p, p + a);
    sort(q, q + b);
    for (int i = 0; i < x; ++i)
        que.push(p[a - i - 1]);
    for (int i = 0; i < y; ++i)
        que.push(q[b - i - 1]);

    ll ans = 0;
    for (int i = 0; i < x + y; ++i) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;

    return 0;
}