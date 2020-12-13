#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        ret[n]++;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    auto mp = prime_factor(n);
    cout << n << ":";
    for (auto t : mp) {
        while (t.second--) {
            cout << " " << t.first;
        }
    }
    cout << endl;

    return 0;
}