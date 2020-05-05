#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

ll l[100000];

int main() {
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
        if (l[i] > n - i) {
            cout << -1 << endl;
            return 0;
        }
        sum += l[i];
    }
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    }
    ll s = 0, f = 0;
    for (int i = 0; i < m; ++i) {
        if (!f && s > n - sum) {
            cout << s + 1;
            s++;
        }
        else {
            f = 1;
            cout << n - sum + 1;
        }
        sum -= l[i];
        if (i < m - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}