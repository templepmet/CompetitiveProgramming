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

int x, y;
void f(int *a) {
    *a = *a + 3;
}

void g(int *b) {
    f(b);
    x = x + 1;
}

void h(int y) {
    if (y > 1) {
        h(y - 1);
        x = (x + 3) * y;
    }
}

int main() {
    x = 1;
    y = 2;
    h(y + 1);
    cout << x << " " << y << endl;
    x = 3;
    y = 4;
    g(&y);
    
    cout << x << " " << y << endl;

    return 0;
}