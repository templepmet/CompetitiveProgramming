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

template<class T>
T gcd(T a, T b){return b ? gcd(b, a % b) : a;}
template<class T>
T lcm(T a, T b){return a / gcd(a, b) * b;}

int b[1000001];

int main() {
    int n, a, s;
    bool p = true;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > 1 && p) {
            for (int i = 1; i * i <= a; ++i) {
                if (a % i == 0) {
                    if ((i > 1 && b[i]) || b[a / i])
                        p = false;
                    b[i] = 1;
                    b[a / i] = 1;
                }
            }
        }

        if (i == 0)
            s = a;
        else
            s = gcd(s, a);
    }
    if (p)
        cout << "pairwise coprime" << endl;
    else if (s == 1)
        cout << "setwise coprime" << endl;
    else
        cout << "not coprime" << endl;

    return 0;
}