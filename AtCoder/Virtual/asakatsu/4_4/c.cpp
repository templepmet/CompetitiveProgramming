#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, m, s[5], c[5];
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> c[i];
        s[i]--;
    }

    for (int i = 0; i < 1000; ++i) {
        string num = to_string(i);
        if (num.size() != n)
            continue;
        bool f = true;
        for (int j = 0; j < m; ++j) {
            if (num[s[j]] != ('0' + c[j])) {
                f = false;
            }
        }
        if (f) {
            cout << num << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}