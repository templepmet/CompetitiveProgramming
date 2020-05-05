#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, ans = 0, suf = 0;
    string s;
    cin >> n >> s;
    while (1) {
        if ((suf = s.find("ABC", suf)) == string::npos)
            break;
        suf++;
        ans++;
    }
    cout << ans << endl;

    return 0;
}