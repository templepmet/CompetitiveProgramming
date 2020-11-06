#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string s[60];
int a[60][60];

int main() {
    int n, m;
    cin >> n >> m;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.') {
                a[i][j] = id++;
            }
        }
    }

    int ans = 0;
    for (int k = 0; k < (1 << id); ++k) {
        bool f = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.' && ((k >> a[i][j]) & 1)) {
                    int cnt = 0;
                    if (i >= 2 && j >= 1 && s[i - 2][j - 1] == '.' && ((k >> a[i - 2][j - 1]) & 1))
                        cnt++;
                    if (i >= 2 && j < m - 1 && s[i - 2][j + 1] == '.' && ((k >> a[i - 2][j + 1]) & 1))
                        cnt++;
                    if (cnt > 0)
                        f = false;
                }
            }
        }
        if (f) ans++;
    }
    cout << ans << endl;

    return 0;
}