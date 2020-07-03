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

int main() {
    int a = 0b011010;
    cout << a <<endl;
    cout << bitset<8>(a) << endl;
    a &= ~0b110;
    cout << a <<endl;
    cout << bitset<8>(a) << endl;
    int n = a & 0xf;
    cout << n << endl;

    return 0;
}