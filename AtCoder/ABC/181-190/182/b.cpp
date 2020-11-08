#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = -1, maxcnt = 0;
    for (int i = 2; i <= 1000; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] % i == 0) {
                cnt++;
            }
        }
        if (chmax(maxcnt, cnt)) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}