#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int n, m;
string s;
int a[100001];

int main() {
    cin >> n >> m >> s;
    a[0] = 1;
    for (int i = 1, j; i <= n; ++i) {
        if (s[i] == '1')
            continue;
        for (j = max(i - m, 0); j < i; ++j) {
            if (a[j] > 0)
                break;
        }
        a[i] = i - j;
    }
    int suf = n;
    vector<int> ans;
    while (suf > 0) {
        int d = a[suf];
        if (d == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(d);
        suf -= d;
    }
    reverse(ans.begin(), ans.end());
    cout << ans[0];
    for (int i = 1, size = ans.size(); i < size; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}