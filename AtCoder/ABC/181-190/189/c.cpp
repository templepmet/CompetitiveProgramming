#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<int, int>;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        for (int j = i - 1; j >= 0 && a[j] >= a[i]; --j) {
            cnt++;
        }
        for (int j = i + 1; j < n && a[j] >= a[i]; ++j) {
            cnt++;
        }
        chmax(ans, a[i] * cnt);
    }
    cout << ans << endl;
    

    return 0;
}