#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n, m;
    int a;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        v.push_back(a);
    }
    v.push_back(0);
    v.push_back(n + 1);
    sort(v.begin(), v.end());
    int k = INF;
    for (int i = 0; i < m + 1; ++i) {
        int w = v[i + 1] - v[i] - 1;
        if (w > 0) {
            k = min(k, w);
        }
    }
    int ans = 0;
    for (int i = 0; i < m + 1; ++i) {
        int w = v[i + 1] - v[i] - 1;
        ans += ((w + k - 1) / k);
    }
    cout << ans << endl;

    return 0;
}