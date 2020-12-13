#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int b[100001];

bool is_prime(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

set<int> eratosthenes(int n) {
    vector<int> v(n + 1, 0);
    set<int> ret;
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n; j += i) {
                v[j] = 1;
            }
            ret.insert(i);
        }
    }
    return ret;
}

int main() {
    int q, l, r;
    auto prime = eratosthenes(100000);
    for (int i = 1; i <= 100000; ++i) {
        if (prime.find(i) != prime.end() && prime.find((i + 1) / 2) != prime.end()) {
            b[i] = 1;
        }
    }
    for (int i = 1; i <= 100000; ++i) {
        b[i] += b[i - 1];
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << b[r] - b[l - 1] << endl;
    }

    return 0;
}