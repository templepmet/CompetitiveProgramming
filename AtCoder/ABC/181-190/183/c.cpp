#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

int t[8][8];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
        }
    }
    int cnt = 0;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += t[a[i]][a[(i + 1) % n]];
        }
        if (sum == k) {
            cnt++;
        }
    } while (next_permutation(a.begin() + 1, a.end()));

    cout << cnt << endl;

    return 0;
}