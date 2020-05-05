#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int a[200000];

int main() {
    int n;
    map<int, ll> mp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll sum = 0;
    for (auto t : mp) {
        sum += (t.second * (t.second - 1)) / 2;
    }
    for (int i = 0; i < n; ++i) {
        ll c = mp[a[i]];
        cout << sum - c * (c - 1) / 2 + (c - 1) * (c - 2) / 2 << endl;
    }

    return 0;
}