#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int a[200000];

int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    int u = -INF, cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o' && i > u + c && cnt <= k) {
            a[i] = cnt;
            u = i;
            cnt++;
        }
    }
    u = INF;
    cnt = k;
    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'o' && i < u - c && cnt > 0) {
            if (a[i] == cnt)
                ans.push_back(i + 1);
            u = i;
            cnt--;
        }
    }
    sort(ans.begin(), ans.end());
    for (int t : ans) {
        cout << t << endl;
    }

    return 0;
}