#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

using P = pair<int, int>;

int main() {
    int n, t;
    cin >> n;
    vector<P> a(1 << n), b;
    for (int i = 0; i < (1 << n); ++i) {
        cin >> t;
        a[i] = make_pair(t, i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int l = a.size();
        b.resize(l / 2);
        for (int j = 0; j < l / 2; j++) {
            b[j] = max(a[2 * j], a[2 * j + 1]);
        }
        a = b;
    }
    cout << min(a[0], a[1]).second + 1 << endl;

    return 0;
}