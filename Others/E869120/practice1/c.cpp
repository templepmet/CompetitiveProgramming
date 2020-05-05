#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    string s, t = "ACGT";
    int cnt = 0, ans = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (t.find(s[i]) != string::npos) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}