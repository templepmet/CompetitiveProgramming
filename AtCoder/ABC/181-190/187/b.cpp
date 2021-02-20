#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int x[1000], y[1000];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xx = x[i] - x[j];
            int yy = y[i] - y[j];
            if (xx < 0) {
                xx *= -1;
                yy *= -1;
            }
            if (-xx <= yy && yy <= xx) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}