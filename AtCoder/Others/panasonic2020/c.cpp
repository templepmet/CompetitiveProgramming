#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (c - a - b < 0)
        cout << "No" << endl;
    else if (4 * a * b < (c - a - b) * (c - a - b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}