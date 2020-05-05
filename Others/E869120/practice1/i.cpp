#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

using ll = long long;

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i <= 999; ++i) {
        int num = i, suf = 0;
        bool f = true;
        for (int j = 0; j < 3; ++j) {
            if ((suf = s.find('0' + num % 10, suf)) == string::npos) {
                f = false;
                break;
            }
            suf++;
            num /= 10;
        }
        if (f)
            ans++;
    }
    cout << ans << endl;

    return 0;
}