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
    if (n > 8) {
        return 0;
    }

    vector<int> d(n), c(n), s(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i] >> c[i] >> s[i];
        p[i] = i;
    }

    ll ans = 0;
    do {
        for (int t = 0; t < (1 << n); ++t) {
            int day = 1;
            ll score = 0;
            for (int i = 0; i < n; ++i) {
                int j = p[i];
                if ((t & (1 << i)) && day + c[j] - 1 <= d[j]) {
                    day += c[j];
                    score += s[j];
                }
            }
            chmax(ans, score);
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;

    return 0;
}

// O(N! N 2^N)