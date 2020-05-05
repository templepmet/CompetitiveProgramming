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
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;

    return 0;
}