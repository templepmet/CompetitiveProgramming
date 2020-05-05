#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int ca, cb, m;
    cin >> ca >> cb >> m;
    int maxc = max(ca, cb);
    int minc = min(ca, cb);
    ll maxv = pow(2LL, maxc) - 1;
    printf("%lld\n", (maxv / m) * (ll)pow(2LL, minc));

    return 0;
}