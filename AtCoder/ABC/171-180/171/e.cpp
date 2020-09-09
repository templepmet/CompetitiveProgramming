#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ a>b?:a=b; }
template<class T> void chmin(T& a, T b){ a<b?:a=b; }

int a[200000];

int main() {
    int n, t = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        t ^= a[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << (t ^ a[i]) << " ";
    }

    return 0;
}