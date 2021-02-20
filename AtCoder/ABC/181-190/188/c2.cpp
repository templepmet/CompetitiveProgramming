#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
    }
    int h = 1 << (n - 1);
    int v = min(*max_element(a.begin(), a.begin() + h), *max_element(a.begin() + h, a.end()));
    int ans = find(a.begin(), a.end(), v) - a.begin() + 1;
    cout << ans << endl;

    return 0;
}