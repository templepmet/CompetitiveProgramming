#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int n;
ll w;
ll b[200001];

int main() {
    cin >> n >> w;
    int s, t;
    ll p;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t >> p;
        b[s] += p;
        b[t] -= p;
    }
    for (int i = 1; i <= 200000; ++i) {
        b[i] += b[i - 1];
    }
    ll v = *max_element(b, b + 200001);
    if (v > w) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}