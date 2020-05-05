#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int cnt(string s, string t) {
    int ret = 0;
    for (int i = 0; i < 26; ++i) {
        if (s.find('a' + i) != string::npos && t.find('a'+ i) != string::npos)
            ret++;
    }
    return ret;
}

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n - 1; ++i) {
        ans = max(ans, cnt(s.substr(0, i), s.substr(i, n)));
    }
    cout << ans << endl;

    return 0;
}