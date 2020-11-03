#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> bool chmax(T& a, T b){ if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b){ if (a > b) { a = b; return true; } return false; }

int main() {
    int n;
    ll x, man = 0, euc = 0, che = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        x = abs(x);
        man += x;
        euc += x * x;
        chmax(che, x);
    }
    cout << man << endl;
    cout << fixed << setprecision(16) << sqrt(euc) << endl;
    cout << che << endl;

    return 0;
}