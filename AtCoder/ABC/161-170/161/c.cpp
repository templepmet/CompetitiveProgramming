#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    cout << min(n % k, k - n % k) << endl;

    return 0;
}